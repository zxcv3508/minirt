#include "minirt.h"

t_vec	vec_ref(t_vec n, t_vec l)
{
	t_vec re;
	t_vec tmp;
	double	dot_p;

	n = vec_unit(n);
	l = vec_unit(l);
	l = vec_make(l.x * -1, l.y * -1, l.z * -1 );
	dot_p = vec_dot(l, n);
	tmp = vec_make(dot_p * 2.0 * n.x, dot_p * 2.0 * n.y, dot_p * 2.0 * n.z);
	re = vec_sub(l, tmp);
	return (vec_unit(re));
}

t_color	make_diffuse(t_ray primary_ray, t_rec *rec, t_light *light)
{
	t_ray	r_l;
	t_color	diffuse;

	r_l.origin = rec->p;
	r_l.dir = vec_unit(vec_sub((light->origin), (rec->p)));
	// printf("diff dot:%f\n ", vec_dot(vec_unit(rec->normal), r_l.dir));
	diffuse = vec_mul(light->c, light->r * fmax(vec_dot(vec_unit(rec->normal), r_l.dir),0.0));
	return (diffuse);
}

t_color	make_spec(t_ray primary_ray, t_rec *rec, t_light *light)
{
	// t_ray	r_l;
	t_color	specular;
	double  ks = 0.5;
	double  ksn = 32.0;
	double  cos;
	double  reflected_strength;
	t_vec   light_dir = vec_unit(vec_sub(light->origin, rec->p));
	t_vec   view_dir = vec_mul(primary_ray.dir, -1.0);
	t_vec   reflected_dir = vec_unit(vec_ref(rec->normal, light_dir));

	cos = fmax(vec_cos(view_dir, reflected_dir), 0.0);
	reflected_strength = pow(cos, ksn);
	specular = vec_mul(vec_mul(light->c, ks), cos);
	// r_l.origin = rec->p;
	// r_l.dir = vec_unit(vec_sub((light->origin), (rec->p)));//
	// specular = vec_mul(light->c, light->r * fmax(pow(vec_dot(vec_ref(rec->normal, r_l.dir), vec_unit(r.dir)),30), 0.0));
	return (specular);
}