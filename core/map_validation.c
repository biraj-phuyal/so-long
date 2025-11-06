/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/06 21:48:36 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_and_update_element(t_game *game, t_map_check *check,
				char c, t_pos pos)
{
	if (!is_valid_char(c))
		print_error_and_exit(game, "Invalid character in map");
	if (c == 'P')
	{
		check->player_count++;
		check->player_x = pos.j;
		check->player_y = pos.i;
	}
	else if (c == 'E')
		check->exit_count++;
	else if (c == 'C')
		check->collectible_count++;
}

void	count_map_elements(t_game *game, t_map_check *check)
{
	t_pos	pos;

	ft_memset(check, 0, sizeof(t_map_check));
	pos.i = 0;
	while (game->map[pos.i])
	{
		pos.j = 0;
		while (game->map[pos.i][pos.j])
		{
			check_and_update_element(game, check, game->map[pos.i][pos.j], pos);
			pos.j++;
		}
		pos.i++;
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

static bool	check_exit_found(char **map_copy, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' && map_copy[i][j] == 'V')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	check_valid_path(t_game *game, t_map_check *check)
{
	char	**map_copy;
	int		collectibles_found;
	bool	exit_found;

	map_copy = duplicate_map(game);
	collectibles_found = 0;
	flood_fill(map_copy, check->player_x, check->player_y,
		&collectibles_found);
	exit_found = check_exit_found(map_copy, game->map);
	strv_free(map_copy);
	if (collectibles_found != check->collectible_count)
		print_error_and_exit(game, "Not all collectibles are reachable");
	if (!exit_found)
		print_error_and_exit(game, "Exit is not reachable");
}
