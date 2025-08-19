/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:19 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/19 11:44:19 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_array(t_map *map)
{
	int fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->file = ft_strjoin(map->file, map->line);
		free(map->line);
		if (!map->file)
			free(map->file);
		map->y++;
	}
	close(fd);
	map->map = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->map || !map->copy)
	{
		free(map->map);
		free(map->copy);
	}
	free(map->file);
}
