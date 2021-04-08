#include "minirt.h"

t_color	make_color(double r, double g, double b)
{
	t_color	color;
	
	color.x = r;
	color.y = g;
	color.z = b;
	
	return (color);
}
