/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:50:32 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/19 14:57:38 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_filename(char *filename)
{
	int	i;
	int len = ft_strlen(filename);
	while (filename[i] != '.')
		i++;
	if (filename[i] != 'b')
		error_on_filename();
	i++;
	if (filename[i] != 'e')
		error_on_filename();
	i++;
	if (filename[i] != 'r')
		error_on_filename();
}

void check_wall(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 1;
	while(map->map[0][x] == '1' && map->map[1][x])
		x++;
	if (map->map[0][x] != '\0')
		error_on_wall(map);
	while (y < map->y)
	{
		if (map->map[y][0] != '1' || map->map[y][x - 1] != '1')
			error_on_wall(map);
		y++;
	}
	x = 0;
	while (map->map[y - 1][x] == '1')
		x++;
	if (map->map[y - 1][x] != '\0')
		error_on_wall(map);
}

void checks(t_map *map)
{
	check_wall(map);
	check_filename(map->filename);
}