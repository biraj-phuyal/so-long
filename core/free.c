/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:11:42 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/23 20:35:17 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(t_game *game, int keycode)
{
	free_image(game->mlx, game->assets.floor);
	free_image(game->mlx, game->assets.wall);
	free_image(game->mlx, game->assets.collectables);
	free_image(game->mlx, game->assets.exit);
	free_image(game->mlx, game->assets.player);
	free_image(game->mlx, game->assets.player_left);
	strv_free(game->map);
	exit(keycode);
}
