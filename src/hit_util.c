/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:42 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:57:43 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point		ray_at(t_ray *ray, double t)
{
	t_point at;

	at = vec_plu(ray->origin, vec_mul(ray->dir, t));
	return (at);
}

void		set_face_normal(t_ray *r, t_rec *rec)
{
	rec->front_face = vec_dot(r->dir, rec->normal) < 0;
	if (rec->front_face)
		rec->normal = rec->normal;
	else
		rec->normal = vec_mul(rec->normal, -1);
}

void		get_record(t_rec *rec, double root, void *obj, t_ray *r)
{
	rec->t = root;
	rec->p = ray_at(r, root);
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
