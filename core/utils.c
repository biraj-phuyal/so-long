/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:10:45 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/31 16:44:30 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**duplicate_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = strv_new(game->map_height + 1);
	i = 0;
	while (game->map[i])
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
			print_error_and_exit(game, "Memory allocation failed");
		i++;
	}
	return (map_copy);
}

void	flood_fill(char **map_copy, int x, int y, int *collectibles)
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
