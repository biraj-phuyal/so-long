/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:29:05 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/21 18:30:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void player(t_game *game)
{
	game->player.right = 0;
	game->player.left = 0;
	while (game->player.right < game->y)
	{
		while (game->player.left < game->x)
		{
			
			game->player.left++;
		}
		game->player.left = 0;
		game->player.right++;
	}
}