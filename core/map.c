/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:17:43 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/23 20:47:33 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*tmp[2];
	char	**map;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	map = NULL;
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		tmp[0] = line;
		tmp[1] = NULL;
		map = strv_join(map, tmp);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = map;
	return (true);
}