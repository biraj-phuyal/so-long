/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:17:43 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/30 18:22:03 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	validate_map(t_game *game)
{
	t_map_check	check;

	if (!game->map || !game->map[0])
		print_error_and_exit(game, "Map is empty");
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	if (game->map_width == 0)
		print_error_and_exit(game, "Map has no width");
	count_map_elements(game, &check);
	if (check.player_count != 1)
		print_error_and_exit(game, "Map must have exactly one player");
	if (check.exit_count != 1)
		print_error_and_exit(game, "Map must have exactly one exit");
	if (check.collectible_count < 1)
		print_error_and_exit(game, "Map must have at least one collectible");
	check_walls(game);
	check_valid_path(game, &check);
	return (true);
}

bool	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*tmp[2];
	char	**map;
	size_t	len;
	size_t	first_len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error_and_exit(game, "Could not open map file");
	line = get_next_line(fd);
	map = NULL;
	first_len = 0;
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		len = ft_strlen(line);
		if (first_len == 0)
			first_len = len;
		else if (len != first_len)
		{
			free(line);
			strv_free(map);
			close(fd);
			print_error_and_exit(game, "Map is not rectangular");
		}
		tmp[0] = line;
		tmp[1] = NULL;
		map = strv_join(map, tmp);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = map;
	return (validate_map(game));
}