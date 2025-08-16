/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:23:07 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/16 13:42:13 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx.h"

void initialize_map(t_map *map)
{
	map->collectibles = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->player_x = 0;
	map->player_y = 0;
	
}

int main(int args, char **argv)
{
	t_map map;

	if (args == 2)
	{
		map.filename = argv[1];
		initialize_map(&map);
	}
	return (0);
}
