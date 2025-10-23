/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:08 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/23 20:35:25 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_PXL 64
# define WND_NAME "so_long"

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx.h"
# include <stdbool.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_img
{
	void	*ptr;
	void	*data;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img;

typedef struct s_assets
{
	t_img		*wall;
	t_img		*player;
	t_img		*player_left;
	t_img		*floor;
	t_img		*collectables;
	t_img		*exit;
}	t_assets;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_assets	assets;
	char	**map;
}	t_game;

t_img	*load_image_from_file(void *mlx, char *path);
void	free_image(void *mlx, t_img *image);
void	ft_exit(t_game *game, int keycode);
char	**strv_new(size_t size);
char	**strv_join(char **strv, char **str);
bool	load_map(t_game *game, char *filename);
size_t	strv_len(char **strv);
void	strv_free(char **strv);

#endif