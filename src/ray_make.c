/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:08 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:07:02 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	make_primary_ray(t_world *world, t_cam *camera, int i, int j)
{
	double	u;
	double	v;
	t_ray	primary_ray;
	t_vec	primary_ray_dir;

	u = (double)i / (double)(world->resolution.x - 1.0);
	v = (double)j / (double)(world->resolution.y - 1.0);
	primary_ray_dir = vec_sub(vec_plu(vec_plu(camera->lower_left_corner,
		(vec_mul(camera->horizontal, u))), vec_mul(camera->vertical, v)),
			camera->look_from);
	primary_ray = make_ray(camera->look_from, vec_unit(primary_ray_dir));
	return (primary_ray);
}

t_ray	make_shadow_ray(t_ray primary_ray, t_light *light, t_rec *rec)
{
	t_ray	shadow_ray;

	shadow_ray.origin = vec_plu(rec->p, vec_mul(rec->normal, 0.000001));
	shadow_ray.dir = vec_sub((light->origin), (rec->p));
	light->len = vec_size(shadow_ray.dir);
	shadow_ray.dir = vec_unit(shadow_ray.dir);
	return (shadow_ray);
}

t_ray	make_ray(t_point o, t_vec dir)
{
	t_ray re;

	re.origin = o;
	re.dir = dir;
	return (re);
}
