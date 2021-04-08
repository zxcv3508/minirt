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

t_color	make_diffuse(t_ray r, t_rec *rec, t_l *light)
{
	t_ray	r_l;
	t_color	diffuse;

	r_l.origin = rec->p;
	r_l.dir = vec_unit(vec_sub((light->origin), (rec->p)));
	diffuse = vec_mul(light->c, light->r * fmax(vec_dot(vec_unit(rec->normal), vec_unit(r_l.dir)),0.0));
	return (diffuse);
}



t_color	make_spec(t_ray r, t_rec *rec, t_l *light)
{
	t_ray	r_l;
	t_color	specular;

	r_l.origin = rec->p;
	r_l.dir = vec_sub((light->origin), (rec->p));//
	specular = vec_mul(light->c, light->r * fmax(pow(vec_dot(vec_ref(rec->normal, r_l.dir), vec_unit(r.dir)),30), 0.0));
	return (specular);
}

int	is_shadow(t_world *world,t_lst *o, t_lst *l, t_rec *rec)
{
	t_rec	rec_l;
	t_ray	l_r;
	int	is_hit;
	t_l *light =(t_l *)(world->l->obj);

	is_hit = 0;
		while (l != NULL)
		{
			l_r.origin
	 = rec->p;
			l_r.dir = vec_sub((light->o), (rec->p));
			
			if ((hit_type(o, l_r, &rec_l) > 0.0))
				is_hit++;
			l = l->next;
		}
	return (is_hit);
}

// t_phong	trace_light(t_world *world, t_ray r, t_rec *rec)
// {
// 	t_phong	re;
// 	t_lst	*l_l = (world->l);
// 	t_l *light =(t_l *)(world->l->obj);
// 	t_lst *o = world->o;
// 	t_ray	r_l;
// 	int	i;
// 	int in_shadow;
// 			t_rec rec_l;
// 		rec_l.t_max = 99999;

// 	i = 0;
// 	while (l_l != NULL)
// 	{
// 		in_shadow = 0;
// 		light = (t_l *)(l_l->obj);
// 		r_l.origi = rec->p;
// 		r_l.dir = vec_sub((light->o), (rec->p));
// 		o = world->o;
// 		while (o != NULL)
// 		{
// 			if (hit_type(o, r_l, &rec_l) == 2)
// 				in_shadow = 1;
// 			o = o->next;
// 		}
// 		i++;
// 		if (!in_shadow)
// 		{
// 			re.s += make_spec(world, r, rec, light);
// 			re.d += make_diffuse(world, r, rec, light);
// 		}
// 		l_l = l_l->next;
// 	}

// 	return (re);
// }