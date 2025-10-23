/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:19 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/23 14:12:24 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void map_array(t_game *game)
{
	int		fd;

	game->y = 0;
	game->line = "";
	game->file = NULL;
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		error_on_filename();
	while (game->line)
	{
		game->line = get_next_line(fd);
		if (game->line == NULL)
			break ;
		game->file = ft_strjoin(game->file, game->line);
		free(game->line);
		if (!game->file)
			exit_after_free(game);
		game->y++;
	}
	close(fd);
	game->map = ft_split(game->file, '\n');
	free(game->file);
}
