#include "minirt.h"

t_world	*init_world()
{
	t_world	*re;

	re = (t_world *)malloc(sizeof(t_world));
	re->o = NULL;
	re->c = NULL;
	re->l = NULL;
	return (re);
}