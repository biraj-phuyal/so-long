/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:08 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/30 18:22:59 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_PXL 64
# define WND_NAME "so_long"
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

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
	int		map_width;
	int		map_height;
}	t_game;

typedef struct s_map_check
{
	int	player_count;
	int	exit_count;
	int	collectible_count;
	int	player_x;
	int	player_y;
}	t_map_check;

t_img	*load_image_from_file(void *mlx, char *path);
void	free_image(void *mlx, t_img *image);
void	ft_exit(t_game *game, int keycode);
char	**strv_new(size_t size);
char	**strv_join(char **strv, char **str);
bool	load_map(t_game *game, char *filename);
size_t	strv_len(char **strv);
void	strv_free(char **strv);
bool	validate_map(t_game *game);
void	print_error_and_exit(t_game *game, char *message);
bool	is_valid_char(char c);
void	count_map_elements(t_game *game, t_map_check *check);
void	check_walls(t_game *game);
void	check_valid_path(t_game *game, t_map_check *check);
void	move_player(t_game *game, int keycode);
void	key_hook(int keycode, t_game *game);
int		exit_game(t_game *game);

#endif