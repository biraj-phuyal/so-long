/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:23:07 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/19 14:21:09 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_map(t_map *map)
{
	map->x = 0;
	map->p = 0;
	map->exit = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->collectibles = 0;
}

int main(int args, char **argv)
{
	t_map map;

	if (args == 2)
	{
		map.filename = argv[1];
		initialize_map(&map);
		checks(&map);
		map.mlx = mlx_init();
	}
	return (0);
}
