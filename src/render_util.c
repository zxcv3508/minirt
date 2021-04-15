/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:12 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:04:29 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		key_press(int keycode, t_world *world)
{
	t_lst	*c_l;
	t_lst	*head;

	c_l = world->cam;
	head = world->camera_head;
	if (keycode == KEY_D)
	{
		if (c_l->next != NULL)
		{
			c_l = c_l->next;
			world->cam = world->cam->next;
			render(world, (t_cam *)(c_l->obj));
		}
		else
		{
			c_l = world->camera_head;
			world->cam = world->camera_head;
			render(world, (t_cam *)(c_l->obj));
		}
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
