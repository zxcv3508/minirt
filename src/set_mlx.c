#include "minirt.h"

void		set_mlx(t_world *world, t_vars *mlx_pointer)
{
	t_data	*img;//molloc?

	img = (t_data *)malloc(sizeof(t_data));
	//img = mlx_pointer->image;
	mlx_pointer->mlx = mlx_init();
	mlx_pointer->win = mlx_new_window(mlx_pointer->mlx, world->resolution.x, world->resolution.y, "Hello world!");
	img->img = mlx_new_image(mlx_pointer->mlx, world->resolution.x, world->resolution.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	mlx_pointer->image = img;
	world->mlx_pointer = mlx_pointer;
	//free(img);
}

// void	set_img(t_data *img, t_vars *vars, t_world **world)
// {
// 	vars->mlx = mlx_init();
// 	vars->win = mlx_new_window(vars->mlx, (*world)->r.x, (*world)->r.y, "Hello world!");
// 	img->img = mlx_new_image(vars->mlx, (*world)->r.x, (*world)->r.y);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
// }