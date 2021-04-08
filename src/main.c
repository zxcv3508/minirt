#include "minirt.h"

int			main(int argc, char const *argv[])
{
	int		fd;
	t_world	world;
	t_vars	mlx_pointer;

	check_argument(argc, argv);
	init_world(&world, argc);
	//parse_world(&world, argv);
	//set_mlx(&world, &mlx_pointer);
	//render(world);

	return 0;
}