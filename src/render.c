#include "minirt.h"

void		render(t_world	*world, t_cam *camera)
{
	int	height;
	int	width;
	int i;
	int j;
	t_color pixel_color;

	height = world->resolution.x;
	width = world->resolution.y;
	j = height -1;
	while (--j >= 0)
	{
		i = -1;
		while(++i < width)
		{
			// if (i == 400 && j == 400)
			// {
				pixel_color = ray_get_color(world, make_primary_ray(world, camera, i, j));
				write_pixel_color_on_mlx_image(world->mlx_pointer->image, i, j, make_rgb(pixel_color));//		my_mlx_pixel_put(&(info->img),i,j,info->rgb);
			// }
		}
	}
	mlx_put_image_to_window(world->mlx_pointer->mlx, world->mlx_pointer->win, world->mlx_pointer->image->img, 0, 0);
}

int		make_rgb(t_color col)
{
	int rgb;

	col.x *= 255;
	col.y *= 255;
	col.z *= 255;
	rgb = (int)col.x + ((int)col.y << 8) + ((int)col.z << 16);
	return (rgb);
}

void			write_pixel_color_on_mlx_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
