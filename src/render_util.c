#include "minirt.h"

double		make_degrees(double radians)
{
	return radians * (M_PI/ 180.0);
}

t_vec		check_vup(t_vec v, t_vec nv)
{
	//if(vec_dot(v,nv) == 0.0)
//	{
//		return (vec_make(1,0,0));
//	}
	return (v);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void	set_img(t_data *img, t_vars *vars, t_world **world)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (*world)->r.x, (*world)->r.y, "Hello world!");
	img->img = mlx_new_image(vars->mlx, (*world)->r.x, (*world)->r.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}