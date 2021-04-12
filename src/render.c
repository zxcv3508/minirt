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

t_ray	make_primary_ray(t_world	*world, t_cam *camera, int i, int j)
{
	double u;
	double v;
	t_ray	primary_ray;
	t_vec	primary_ray_dir;
	
	u = (double)i / (double)(world->resolution.x - 1.0);
	v = (double)j / (double)(world->resolution.y - 1.0);
	primary_ray_dir = vec_sub(vec_plu(vec_plu(camera->lower_left_corner, (vec_mul(camera->horizontal, u))), vec_mul(camera->vertical, v)), camera->look_from);
	//primary_ray_dir = vec_unit(vec_sub(vec_plu((vec_mul(camera->vertical, v), vec_mul(camera->horizontal, u)),camera->lower_left_corner), camera->look_from));
	primary_ray = make_ray(camera->look_from, vec_unit(primary_ray_dir));
	 //if(i ==1 && j ==1)
	// printf("%f %f\n", u,v);
	//printf("dir %f,%f,%f ori %f,%f,%f\n", primary_ray.dir.x,primary_ray.dir.y,primary_ray.dir.z, primary_ray.origin.x,primary_ray.origin.y,primary_ray.origin.z);
	return (primary_ray);
}

// void	make_world(t_world **world, int is_save)
// {
// 	t_info *info;

// 	info = (t_info *)malloc(sizeof(t_info));
// 	info->world = *world;
// 	info->camera_head = (*world)->c;
// 	set_img (&(info->img), &(info->vars), world);
// 	cam_set(info, ((t_cam *)((*world)->c->obj)));
// 	image_rend(info);
// 	mlx_hook(info->vars.win, 2,  0, &key_press, info);
// 	mlx_loop(info->vars.mlx);
// 	free(info);
// }

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
