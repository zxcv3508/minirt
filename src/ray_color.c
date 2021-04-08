#include "minirt.h"

int		ray_col(t_world **world, t_ray r)
{
	t_lst *obj_l;
	t_lst *lig_l;
	t_rec  rec;
	t_phong	p;
	double l;
	double d;
	double a;
	int pixel;

	rec.t_max = 999999999.0;
	
	rec.col = 0;
	a = (*world)->a.r;
	obj_l = (*world)->o;
	lig_l = (*world)->l;
	int t;
	while (obj_l != NULL)
	{	
		hit_type(obj_l, r, &rec);
		obj_l = obj_l->next;
	}
		t = rec.col;
	if (t > 0 )
	{
		rec.t_max = 999999999.0;
		p = trace_light(*world, r, &rec);
		
			printf("l :%f d : %f a : %f\n",p.s, p.d ,a);
		// return (col_plu(col_mul(rgb_to_col(t), a + p.d), col_mul(((t_l *)(lig_l->obj))->c, p.s)));
pixel = col_mul(rgb_to_col(t) , p.d + p.s);
		return (pixel);
	}
	return (0);
}