/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:37 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:57:38 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec)
{
	t_vec oc;
	double root;
	double sqrted; 
	double a;
	double hb;
	double c;
	double d;
	
	oc = vec_sub(r.origin, o.origin);
	a = vec_dot(r.dir, r.dir);
	hb = vec_dot(oc, r.dir);
	c = vec_dot(oc, oc) - (o.r * o.r);
	d = hb * hb - a * c;
	if (d < 0.000000)
		return (0);
	sqrted = sqrt(d);
	root = (-hb - sqrted) / a;
	if (root < t_min || rec->t_max < root)
	{
		root = (-hb + sqrted) / a;
		if (root < t_min || rec->t_max < root)
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(&r, root);
	rec->normal = vec_mul(vec_sub(rec->p, o.origin), 1.0 / o.r);
	rec->albedo = o.c;
	rec->t_max = root;
	set_face_normal(&r, rec);
	return (1);
}
