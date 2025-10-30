/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:23:07 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/30 18:22:24 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_assets(t_game *game)
{
	game->assets.floor = load_image_from_file(game->mlx,
			"assets/images/so-long-floor.xpm");
	game->assets.wall = load_image_from_file(game->mlx,
			"assets/images/so-long-wall.xpm");
	game->assets.collectables = load_image_from_file(game->mlx,
			"assets/images/dumpling.xpm");
	game->assets.exit = load_image_from_file(game->mlx,
			"assets/images/so-long-exit.xpm");
	game->assets.player = load_image_from_file(game->mlx,
			"assets/images/player.xpm");
	game->assets.player_left = load_image_from_file(game->mlx,
			"assets/images/player_left.xpm");
	if (!game->assets.floor || !game->assets.wall || !game->assets.collectables
		|| !game->assets.exit || !game->assets.player || !game->assets.player_left)
	{
		write(2, "Error\nFailed to load assets\n", 29);
		exit(EXIT_FAILURE);
	}
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	t_img	*image;

	if (tile == '1')
		image = game->assets.wall;
	else if (tile == '0')
		image = game->assets.floor;
	else if (tile == 'C')
		image = game->assets.collectables;
	else if (tile == 'E')
		image = game->assets.exit;
	else if (tile == 'P')
		image = game->assets.player;
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

void	loop(t_game *game)
{
	render_map(game);
}

int	main(int args, char **argv)
{
	static t_game	game;

	if (args != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		exit(EXIT_FAILURE);
	}
	game.mlx = mlx_init();
	load_assets(&game);
	if (!load_map(&game, argv[1]))
	{
		write(2, "Error\nCould not load map\n", 26);
		ft_exit(&game, EXIT_FAILURE);
	}
	game.win = mlx_new_window(game.mlx, game.map_width * IMG_PXL,
			game.map_height * IMG_PXL, WND_NAME);
	mlx_key_hook(game.win, (void *)key_hook, &game);
	mlx_loop_hook(game.mlx, (void *)loop, &game);
	mlx_hook(game.win, 17, 0, (void *)exit_game, &game);
	mlx_loop(game.mlx);
}
