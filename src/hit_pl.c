/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:35 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:57:36 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec)
{
	double	denom;
	double	t;
	t_vec	to_hit;

	denom = vec_dot(o.nv, r.dir);
	if (fabs(denom) < 1e-6)
		return (FALSE);
	to_hit = vec_sub(o.origin, r.origin);
	t = vec_dot(to_hit, o.nv) / denom;
	if (t < t_min || t > rec->t_max)
		return (FALSE);
	get_record(rec, t, &o, &r);
	rec->normal = o.nv;
	rec->albedo = o.c;
	set_face_normal(&r, rec);
	return (TRUE);
}
