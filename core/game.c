/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:23:07 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/04 22:12:30 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx.h"

int main(void)
{
	t_data	data;
	t_img	floor_img;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	
	make_map();

	floor_img.img = mlx_xpm_file_to_image(data.mlx, "assets/images/so-long-floor.xpm", &floor_img.width, &floor_img.height);
	if (!floor_img.img)
	{
		free(data.mlx);
		return (1);
	}
	
	data.win = mlx_new_window(data.mlx, 800, 600, "My Window");
	if (!data.win)
		return (free(data.mlx), 1);
	mlx_loop(data.mlx);
	return (0);
}