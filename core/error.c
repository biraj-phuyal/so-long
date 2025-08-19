/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:10:08 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/19 13:16:40 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_filename(void)
{
	write(2, "Filename should be a BER extension file\n", 45);
	exit(EXIT_FAILURE);
}

void	error_on_wall(t_map *map)
{
	write(2, "failed in wall\n", 15);
	free_the_array(map->map, map->y);
	free_the_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

void	error_openfile(void)
{
	write(2, "failed to open\n", 15);
	exit(EXIT_FAILURE);
}

void	error_size(t_map *map)
{
	write(2, "failed in size\n", 15);
	free_the_array(map->map, map->y);
	free_the_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

void	error_map_elements(t_map *map)
{
	write(2, "failed in elements\n", 19);
	free_the_array(map->map, map->y);
	free_the_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}