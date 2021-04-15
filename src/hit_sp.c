/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:37 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:52:16 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec)
{
	t_sp_set sp_set;

	sp_set.oc = vec_sub(r.origin, o.origin);
	sp_set.a = vec_dot(r.dir, r.dir);
	sp_set.hb = vec_dot(sp_set.oc, r.dir);
	sp_set.c = vec_dot(sp_set.oc, sp_set.oc) - (o.r * o.r);
	sp_set.d = sp_set.hb * sp_set.hb - sp_set.a * sp_set.c;
	if (sp_set.d < 0.000000)
		return (0);
	sp_set.sqrted = sqrt(sp_set.d);
	sp_set.root = (-sp_set.hb - sp_set.sqrted) / sp_set.a;
	if (sp_set.root < t_min || rec->t_max < sp_set.root)
	{
		sp_set.root = (-sp_set.hb + sp_set.sqrted) / sp_set.a;
		if (sp_set.root < t_min || rec->t_max < sp_set.root)
			return (0);
	}
	rec->t = sp_set.root;
	rec->p = ray_at(&r, sp_set.root);
	rec->normal = vec_mul(vec_sub(rec->p, o.origin), 1.0 / o.r);
	rec->albedo = o.c;
	rec->t_max = sp_set.root;
	set_face_normal(&r, rec);
	return (1);
}
