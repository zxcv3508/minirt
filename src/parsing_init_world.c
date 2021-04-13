#include "minirt.h"

void		init_world(t_world *world, int argc)
{
	world->object = NULL;
	world->light = NULL;
	world->cam = NULL;
	world->mlx_pointer = NULL;
	world->camera_head = NULL;
	
	if (argc == 3)
		world->is_save = 1;
	else
		world->is_save = 0;
}