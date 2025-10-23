/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:17:43 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/23 21:07:28 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error_and_exit(t_game *game, char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (game->map)
		strv_free(game->map);
	exit(EXIT_FAILURE);
}

static bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static void	count_map_elements(t_game *game, t_map_check *check)
{
	int	i;
	int	j;

	ft_memset(check, 0, sizeof(t_map_check));
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_valid_char(game->map[i][j]))
				print_error_and_exit(game, "Invalid character in map");
			if (game->map[i][j] == 'P')
			{
				check->player_count++;
				check->player_x = j;
				check->player_y = i;
			}
			else if (game->map[i][j] == 'E')
				check->exit_count++;
			else if (game->map[i][j] == 'C')
				check->collectible_count++;
			j++;
		}
		i++;
	}
}

static void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->map_height - 1)
			{
				if (game->map[i][j] != '1')
					print_error_and_exit(game, "Map not enclosed by walls");
			}
			if (j == 0 || j == game->map_width - 1)
			{
				if (game->map[i][j] != '1')
					print_error_and_exit(game, "Map not enclosed by walls");
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **map_copy, int x, int y, int *collectibles)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		(*collectibles)++;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, collectibles);
	flood_fill(map_copy, x - 1, y, collectibles);
	flood_fill(map_copy, x, y + 1, collectibles);
	flood_fill(map_copy, x, y - 1, collectibles);
}

static void	check_valid_path(t_game *game, t_map_check *check)
{
	char	**map_copy;
	int		i;
	int		collectibles_found;
	bool	exit_found;

	map_copy = strv_new(game->map_height + 1);
	i = 0;
	while (game->map[i])
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
			print_error_and_exit(game, "Memory allocation failed");
		i++;
	}
	collectibles_found = 0;
	flood_fill(map_copy, check->player_x, check->player_y, &collectibles_found);
	exit_found = false;
	i = 0;
	while (game->map[i])
	{
		int j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E' && map_copy[i][j] == 'V')
				exit_found = true;
			j++;
		}
		i++;
	}
	strv_free(map_copy);
	if (collectibles_found != check->collectible_count)
		print_error_and_exit(game, "Not all collectibles are reachable");
	if (!exit_found)
		print_error_and_exit(game, "Exit is not reachable");
}

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