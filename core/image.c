/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:29:05 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/23 20:35:08 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*load_image_from_file(void *mlx, char *path)
{
	t_img	*image;
	int		width;
	int		height;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	image->ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!image->ptr)
	{
		free(image);
		return (NULL);
	}
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->size_l, &image->endian);
	return (image);
}

void	free_image(void *mlx, t_img *image)
{
	if (image)
	{
		if (image->ptr)
			mlx_destroy_image(mlx, image->ptr);
		free(image);
	}
}