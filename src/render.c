/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:14 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 12:47:47 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_world *world, t_cam *camera)
{
	int		height;
	int		width;
	int		i;
	int		j;
	t_color pixel_color;

	height = world->resolution.x;
	width = world->resolution.y;
	j = height - 1;
	while (--j >= 0)
	{
		i = -1;
		while (++i < width)
		{
			pixel_color = ray_get_color(world,
				make_primary_ray(world, camera, i, j));
			write_pixel_color_on_mlx_image(world->mlx_pointer->image,
				i, j, make_rgb(pixel_color));
		}
	}
	mlx_put_image_to_window(world->mlx_pointer->mlx,
		world->mlx_pointer->win, world->mlx_pointer->image->img, 0, 0);
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

void	write_pixel_color_on_mlx_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
