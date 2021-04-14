#include "minirt.h"

int 	hit_sq(t_sq o, t_ray r, double t_min,  t_rec *rec)
{
	double			root;
	t_point			p;

	root = vec_dot(vec_sub(o.origin, r.origin), o.nv)
							/ vec_dot(o.nv, r.dir);
	if (root < 0 || root < rec->t_min || root > rec->t_max)
		return (0);
	p = ray_at(&r, root);
	if (is_inside_square(&o, p) == FALSE)
		return (FALSE);
	get_record(rec, root, &o, &r);
	rec->normal = vec_unit(o.nv);
	rec->albedo = o.c;
	rec->t_max = root;
	set_face_normal(&r, rec);
	return (TRUE);
}

int		is_inside_square(t_sq *square, t_point p)
{
	if (is_aligned(square->nv) == 100)
	{
		if (!(fabs(p.y - square->origin.y) <= (square->r / 2.0)
			&& fabs(p.z - square->origin.z) <= (square->r / 2.0)))
			return (0);
	}
	else if (is_aligned(square->nv) == 101)
	{
		if (!(fabs(p.z - square->origin.z) <= (square->r / 2.0)
			&& fabs(p.x - square->origin.x) <= (square->r / 2.0)))
			return (0);
	}
	else if (is_aligned(square->nv) == 102)
	{
		if (!(fabs(p.y - square->origin.y) <= (square->r / 2.0)
			&& fabs(p.x - square->origin.x) <= (square->r / 2.0)))
			return (0);
	}
	return (1);
}

int			is_aligned(t_vec vec)
{
	if (fabs(vec.x) == 1 && fabs(vec.y) == 0 && fabs(vec.z) == 0)
		return (100);
	else if (fabs(vec.x) == 0 && fabs(vec.y) == 1 && fabs(vec.z) == 0)
		return (101);
	else if (fabs(vec.x) == 0 && fabs(vec.y) == 0 && fabs(vec.z) == 1)
		return (102);
	return (0);
}