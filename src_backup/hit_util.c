#include "minirt.h"
t_point	ray_at(t_ray *ray, double t)
{
	t_point at;

	at = vec_plu(ray->origin, vec_mul(ray->dir, t));
	return (at);
}
void	set_face_normal(t_ray *r, t_rec *rec)
{
	rec->front_face = vec_dot(r->dir, rec->normal) < 0;
	if (rec->front_face)
		rec->normal = rec->normal;
	else
		rec->normal = vec_mul(rec->normal, -1);
}

void		get_record(t_rec *rec, double root, void *obj, t_ray *r)
{
	//rec->texture = obj->texture;
	rec->t = root;
	rec->p = ray_at(r, root);
}
