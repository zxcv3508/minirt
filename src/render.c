#include "minirt.h"

void	make_world(t_world **world, int is_save)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	info->world = *world;
	info->camera_head = (*world)->c;
	set_img (&(info->img), &(info->vars), world);
	cam_set(info, ((t_cam *)((*world)->c->obj)));
	image_rend(info);
	mlx_hook(info->vars.win, 2,  0, &key_press, info);
	mlx_loop(info->vars.mlx);
	free(info);
}


t_color		ray_get_color(t_world *world)
{
	t_color		pixel_color;

	pixel_color = color(0,0,0);
	if (hit())
		pixel_color = get_phong_color();
	else
		pixel_color = get_background_color();
	return (pixel_color);
}

void		render(t_world	*world)
{
	int i;
	int j;
	t_vec primary_ray;
	t_ray r_tmpixel_colorp;
	
	i = -1;
	while (++i < height)
	{
		j = 0;
		while(++j < width)
		{
			primary_ray = make_primary_ray();//v_tmp = vec_make(->llc.x + u * info->hor.x + v * info->ver.x - info->ori.x, info->llc.y + u * info->hor.y + v * info->ver.y - info->ori.y, info->llc.z + u * info->hor.z + v * info->ver.z - info->ori.z);
			                                // t_ray r_tmp = make_ray(info->ori, v_tmp);
			pixel_color = ray_get_color(primary_ray, world);
			write_pixel_color_on_mlx_image();//		my_mlx_pixel_put(&(info->img),i,j,info->rgb);

		}
	}
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, info->img.img, 0, 0);
}

int		key_press(int keycode, t_info *info)
{
	t_lst	*c_l;
	t_lst	*head;

	c_l = info->world->c;
	head = info->world->c;
	if (keycode == KEY_D)
	{
		if (c_l->next != NULL)
		{
		printf("1\n");
			c_l = c_l->next;
			info->world->c = info->world->c->next;
			cam_set(info, ((t_cam *)(c_l->obj)));
			image_rend(info);
		}
		else
		{
		printf("2\n");
			c_l = c_l->next;
			c_l = info->camera_head;;
			info->world->c = info->camera_head;
			cam_set(info, ((t_cam *)(c_l->obj)));
			image_rend(info);
		}
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

