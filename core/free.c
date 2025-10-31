/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:11:42 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/31 16:00:32 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(t_game *game, int keycode)
{
	free_image(game->mlx, game->floor);
	free_image(game->mlx, game->wall);
	free_image(game->mlx, game->collectables);
	free_image(game->mlx, game->exit);
	free_image(game->mlx, game->player);
	free_image(game->mlx, game->player_left);
	strv_free(game->map);
	exit(keycode);
}
