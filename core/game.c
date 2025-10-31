/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:23:07 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/31 16:45:52 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_single_assets(t_game *game)
{
	game->floor = load_image_from_file(game->mlx,
			"assets/images/so-long-floor.xpm");
	game->wall = load_image_from_file(game->mlx,
			"assets/images/so-long-wall.xpm");
	game->collectables = load_image_from_file(game->mlx,
			"assets/images/monster.xpm");
}

static void	load_player_assets(t_game *game)
{
	game->exit = load_image_from_file(game->mlx,
			"assets/images/so-long-exit.xpm");
	game->player = load_image_from_file(game->mlx,
			"assets/images/player.xpm");
	game->player_left = load_image_from_file(game->mlx,
			"assets/images/player_left.xpm");
}

void	load_assets(t_game *game)
{
	load_single_assets(game);
	load_player_assets(game);
	if (!game->floor || !game->wall
		|| !game->collectables || !game->exit
		|| !game->player || !game->player_left)
	{
		write(2, "Error\nFailed to load assets\n", 29);
		exit(EXIT_FAILURE);
	}
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	t_img	*image;

	if (tile == '1')
		image = game->wall;
	else if (tile == '0')
		image = game->floor;
	else if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor->ptr, x * IMG_PXL, y * IMG_PXL);
		if (game->player_direction == 1)
			image = game->player_left;
		else
			image = game->player;
	}
	else if (tile == 'C')
		image = game->collectables;
	else if (tile == 'E')
		image = game->exit;
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->win,
		image->ptr, x * IMG_PXL, y * IMG_PXL);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			render_tile(game, game->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
