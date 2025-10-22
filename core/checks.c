/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:50:32 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/22 12:55:02 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_filename(char *filename)
{
	int	i;
	i = ft_strlen(filename);
	if (i < 4)
		error_on_filename();
	if (filename[i - 4] != '.')
		error_on_filename();
	if (filename[i - 3] != 'b')
		error_on_filename();
	if (filename[i - 2] != 'e')
		error_on_filename();
	if (filename[i - 1] != 'r')
		error_on_filename();
}


void check_elements_of_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->map[y][x] == 'C')
				game->c += 1;
			else if (game->map[y][x] == 'E')
				game->e += 1;
			else if (game->map[y][x] == 'P')
				game->p += 1;
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				error_on_map_elements(game);
			x++;
		}
		y++;
	}
	if (game->c < 1 || game->e < 1 || game->p != 1)
		error_on_map_elements(game);
}

void check_size(t_game *game)
{
	int	x;
	int	y;
	int max;

	x = 0;
	y = 0;
	max = ft_strlen(game->map[y]);
	while (y < game->y)
	{
		x = ft_strlen(game->map[y]);
		if (max != x)
			error_on_size(game);
		y++;
	}
	game->x = max;
}

void check_wall(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 1;
	while(game->map[0][x] == '1' && game->map[0][x])
		x++;
	if (game->map[0][x] != '\0')
		error_on_wall(game);
	while (y < game->y)
	{
		if (game->map[y][0] != '1' || game->map[y][game->x - 1] != '1')
			error_on_wall(game);
		y++;
	}
	x = 0;
	while (game->map[y - 1][x] == '1' && game->map[y - 1][x])
		x++;
	if (game->map[y - 1][x] != '\0')
		error_on_wall(game);
}

void load_map(t_game *game)
{
	check_filename(game->filename);
	map_array(game);
	check_size(game);
	check_wall(game);
	check_elements_of_map(game);
}