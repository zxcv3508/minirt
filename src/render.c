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

void	image_rend(t_info *info)
{
	int i;
	int j;
	double u;
	double v;
	t_vec v_tmp;
	t_ray r_tmp;

	j = info->world->r.y -1;
	while (j >= 0)
	{
		i = 0;
		while(i < info->world->r.x)
		{
			u = (double)i / (double)(info->world->r.x-1.0);
			v = (double)j / (double)(info->world->r.y-1.0);
			v_tmp = vec_make(->llc.x + u * info->hor.x + v * info->ver.x - info->ori.x, info->llc.y + u * info->hor.y + v * info->ver.y - info->ori.y, info->llc.z + u * info->hor.z + v * info->ver.z - info->ori.z);
			t_ray r_tmp = make_ray(info->ori, v_tmp);
			//printf("%d, %d :",i,j);
			info->rgb = ray_col(&(info->world), r_tmp);
			my_mlx_pixel_put(&(info->img),i,j,info->rgb);
			i++;
		}
		j--;
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

