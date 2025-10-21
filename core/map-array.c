/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:19 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/21 18:30:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void map_array(t_game *game)
{
	game->map = ft_split(game->file, '\n');
	game->copy = ft_split(game->file, '\n');
	if (!game->map || !game->copy)
	{
		if (game->map)
			free_the_array(game->map, game->y);
		if (game->copy)
			free_the_array(game->copy, game->y);
		free(game->file);
		game->file = NULL;
		exit(EXIT_FAILURE);
	}
	free(game->file);
	game->file = NULL;
}
