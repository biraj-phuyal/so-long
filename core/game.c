#include "mlx.h"
#include <stdlib.h>

int main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "My Window");
	if (!window)
		return (free(mlx), 1);
	mlx_loop(mlx);
	return (0);
}