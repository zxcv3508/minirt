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