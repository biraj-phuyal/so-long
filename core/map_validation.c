/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/30 19:43:47 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_map_elements(t_game *game, t_map_check *check)
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

void	check_walls(t_game *game)
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

void	check_valid_path(t_game *game, t_map_check *check)
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
