/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_phong_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:10 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:29:34 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		vec_ref(t_vec n, t_vec l)
{
	t_vec	re;
	t_vec	tmp;
	double	dot_p;

	n = vec_unit(n);
	l = vec_unit(l);
	l = vec_make(l.x * -1, l.y * -1, l.z * -1);
	dot_p = vec_dot(l, n);
	tmp = vec_make(dot_p * 2.0 * n.x, dot_p * 2.0 * n.y, dot_p * 2.0 * n.z);
	re = vec_sub(l, tmp);
	return (vec_unit(re));
}

t_color		make_diffuse(t_ray primary_ray, t_rec *rec, t_light *light)
{
	t_ray	r_l;
	t_color	diffuse;

	r_l.origin = rec->p;
	r_l.dir = vec_unit(vec_sub((light->origin), (rec->p)));
	diffuse = vec_mul(light->c, light->r *
		fmax(vec_dot(vec_unit(rec->normal), r_l.dir), 0.0));
	return (diffuse);
}

t_color		make_spec(t_ray primary_ray, t_rec *rec, t_light *light)
{
	t_color	specular;
	t_vec	light_dir;
	t_vec	view_dir;
	t_vec	reflected_dir;
	double	reflected_strength;

	light_dir = vec_unit(vec_sub(light->origin, rec->p));
	view_dir = vec_mul(primary_ray.dir, -1.0);
	reflected_dir = vec_unit(vec_ref(rec->normal, light_dir));
	reflected_strength = pow(fmax(vec_cos(view_dir, reflected_dir), 0.0), 32.0);
	specular = vec_mul(vec_mul(light->c, 0.5),
		fmax(vec_cos(view_dir, reflected_dir), 0.0));
	return (specular);
}
