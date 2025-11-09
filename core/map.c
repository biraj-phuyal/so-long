/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:17:43 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/09 00:18:57 by biphuyal         ###   ########.fr       */
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
	game->collectibles_remaining = check.collectible_count;
	check_walls(game);
	check_valid_path(game, &check);
	return (true);
}

static void	handle_map_error(char *line, char **map, int fd, t_game *game)
{
	free(line);
	strv_free(map);
	close(fd);
	print_error_and_exit(game, "Map is not rectangular");
}

static void	add_line_to_map(char *line, char ***map)
{
	char	*tmp[2];

	tmp[0] = line;
	tmp[1] = NULL;
	*map = strv_join(*map, tmp);
}

static char	**read_map_file(int fd, t_game *game)
{
	char	*line;
	char	**map;
	size_t	first_len;
	size_t	len;

	map = NULL;
	first_len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (first_len == 0)
			first_len = len;
		else if (len != first_len)
			handle_map_error(line, map, fd, game);
		add_line_to_map(line, &map);
		line = get_next_line(fd);
	}
	return (map);
}

bool	load_map(t_game *game, char *filename)
{
	int		fd;
	char	**map;

	if (!check_filename(filename))
		print_error_and_exit(game, "Invalid file extention");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error_and_exit(game, "Could not open map file");
	map = read_map_file(fd, game);
	close(fd);
	game->map = map;
	return (validate_map(game));
}
