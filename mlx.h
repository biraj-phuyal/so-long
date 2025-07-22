/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:20:24 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/19 21:28:51 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	t_map		*map;
}	t_data;

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int width, int height, const char *title);
int		mlx_loop(void *mlx_ptr);
void	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
void	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
void	*mlx_xpm_file_to_image(void *mlx_ptr, const char *filename, int *width, int *height);
void	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
void	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int		mlx_key_hook(void *win_ptr, int (*func)(int keycode, void *param));
int		mlx_loop_hook(void *mlx_ptr, int (*func)(void *param), void *param);
int		mlx_mouse_hook(void *win_ptr, int (*func)(int button, int x, int y, void *param));
int		mlx_expose_hook(void *win_ptr, int (*func)(void *param), void *param);
int		mlx_destroy(void *mlx_ptr);
void	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, const char *string);
int		mlx_get_screen_size(void *mlx_ptr, int *width, int *height);
int		mlx_mouse_move(void *win_ptr, int x, int y);
int		mlx_mouse_hide(void *win_ptr);
int		mlx_mouse_show(void *win_ptr);
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y );
int		mlx_mouse_set_pos(void *win_ptr, int x, int y);
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*func)(), void *param);
int		mlx_get_data_addr(void *img_ptr, int *bpp, int *size_line, int *endian);
void	mlx_pixel_put   (void *mlx_ptr, void *win_ptr, int x, int y, int color);
void	mlx_destroy_display(void *mlx_ptr);
void	mlx_destroy_image(void *mlx_ptr, void *img_ptr);