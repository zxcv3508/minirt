/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:40 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:30:18 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_tr(t_tr o, t_ray r, double t_min, t_rec *rec)
{
	double		t;
	double		denom;
	t_point		to_hit;
	t_point		p;

	o.nv = vec_unit(vec_cro(vec_sub((o.p2), (o.p1)), vec_sub((o.p3), (o.p1))));
	denom = vec_dot(o.nv, r.dir);
	if (fabs(denom) < 1e-6)
		return (FALSE);
	to_hit = vec_sub(o.p1, r.origin);
	t = vec_dot(to_hit, o.nv) / denom;
	if (t < t_min || t > rec->t_max)
		return (FALSE);
	p = ray_at(&r, t);
	if (!(is_inside(o.p1, o.p2, o.p3, p)))
		return (FALSE);
	get_record(rec, t, &o, &r);
	rec->normal = o.nv;
	rec->albedo = o.c;
	rec->t_max = t;
	set_face_normal(&r, rec);
	return (TRUE);
}

int		is_inside(t_point p1, t_point p2, t_point p3, t_point p)
{
	t_vec	v1;
	t_vec	v2;

	v1 = vec_cro(vec_sub((p2), (p1)), vec_sub((p), (p1)));
	v2 = vec_cro(vec_sub((p2), (p1)), vec_sub((p3), (p1)));
	if (vec_dot(v1, v2) < 0)
		return (0);
	v1 = vec_cro(vec_sub((p3), (p1)), vec_sub((p), (p1)));
	v2 = vec_cro(vec_sub((p3), (p1)), vec_sub((p2), (p1)));
	if (vec_dot(v1, v2) < 0)
		return (0);
	v1 = vec_cro(vec_sub((p2), (p3)), vec_sub((p), (p3)));
	v2 = vec_cro(vec_sub((p2), (p3)), vec_sub((p1), (p3)));
	if (vec_dot(v1, v2) < 0)
		return (0);
	return (1);
}
