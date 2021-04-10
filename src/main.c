#include "minirt.h"

int			main(int argc, char *argv[])
{
	int		fd;
	t_world	world;
	t_vars	mlx_pointer;

	if(!check_argument(argc, argv))
		return (0);
	init_world(&world, argc);
	parse_world(&world, argv);
	set_mlx(&world, &mlx_pointer);
	render(&world, (t_cam *)(world.cam->obj));
	mlx_hook(world.mlx_pointer->win, 2,  0, &key_press, &world);
	mlx_loop(world.mlx_pointer->mlx);
	free_world(&world);


	return 0;
}