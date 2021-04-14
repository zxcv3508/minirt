/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:46 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:57:47 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			main(int argc, char *argv[])
{
	int		fd;
	t_world	world;
	t_vars	mlx_pointer;

	ft_memset(&world, 0, sizeof(t_world));
	if (!check_argument(argc, argv))
		exit(0);
	init_world(&world, argc);
	if (!parse_world(&world, argv))
		exit(printf("error") * 0);
	set_mlx(&world, &mlx_pointer);
	render(&world, (t_cam *)(world.cam->obj));
	if (world.is_save)
		bmp_save(&world);
	mlx_hook(world.mlx_pointer->win, 2,  0, &key_press, &world);
	mlx_loop(world.mlx_pointer->mlx);
	free_world(&world);
	return (0);
}
