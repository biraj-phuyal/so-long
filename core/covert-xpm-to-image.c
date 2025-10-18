/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   covert-xpm-to-image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:29:05 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/18 16:12:15 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map *convert_recourses_to_image(t_map *map)
{
	int size;

	size = 64;
	map->img.floor = mlx_xpm_file_to_image(map->mlx,
			"../assets/so-long-floor.xpm", size, size);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"../assets/so-long-wall.xpm", size, size);
	map->img.collectables = mlx_xpm_file_to_image(map->mlx,
			"../assets/dumpling.xpm", size, size);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
			"../assets/so-long-exit.xpm", size, size);
}