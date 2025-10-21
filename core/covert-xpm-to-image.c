/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   covert-xpm-to-image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:29:05 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/21 17:12:21 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void convert_recourses_to_image(t_game *game)
{
	int size;

	size = 64;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"../assets/so-long-floor.xpm", size, size);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"../assets/so-long-wall.xpm", size, size);
	game->img.collectables = mlx_xpm_file_to_image(game->mlx,
			"../assets/dumpling.xpm", size, size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"../assets/so-long-exit.xpm", size, size);
	convert_player_to_image(game);
}

void convert_player_to_image(t_game *game)
{
	int size;

	size = 64;
	game->img.player_up = mlx_xpm_file_to_image(game->mlx,
			"../assets/so-long-player_up.xpm", size, size);
	game->img.player_down = mlx_xpm_file_to_image(game->mlx,
			"../assets/so-long-player_down.xpm", size, size);
	game->img.player_right = mlx_xpm_file_to_image(game->mlx,
			"../assets/so-long-player_right.xpm", size, size);
	game->img.player_left = mlx_xpm_file_to_image(game->mlx,
			"../assets/so-long-player_left.xpm", size, size);
}