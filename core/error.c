/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:10:08 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/21 17:12:30 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_on_filename(void)
{
	write(2, "Filename should be a .ber extension file\n", 41);
	exit(EXIT_FAILURE);
}

void	error_on_wall(t_game *game)
{
	write(2, "failed in wall\n", 15);
	free_the_array(game->map, game->y);
	free_the_array(game->copy, game->y);
	exit(EXIT_FAILURE);
}

void	error_on_openfile(void)
{
	write(2, "failed to open\n", 15);
	exit(EXIT_FAILURE);
}

void	error_on_size(t_game *game)
{
	write(2, "failed in size\n", 15);
	free_the_array(game->map, game->y);
	free_the_array(game->copy, game->y);
	exit(EXIT_FAILURE);
}

void	error_on_map_elements(t_game *game)
{
	write(2, "failed in elements\n", 19);
	free_the_array(game->map, game->y);
	free_the_array(game->copy, game->y);
	exit(EXIT_FAILURE);
}