/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:15 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:07:43 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		set_mlx(t_world *world, t_vars *mlx_pointer)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(t_data));
	mlx_pointer->mlx = mlx_init();
	mlx_pointer->win = mlx_new_window(mlx_pointer->mlx,
		world->resolution.x, world->resolution.y, "Hello world!");
	img->img = mlx_new_image(mlx_pointer->mlx, world->resolution.x,
		world->resolution.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	mlx_pointer->image = img;
	world->mlx_pointer = mlx_pointer;
}
