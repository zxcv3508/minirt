/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:31 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:57:32 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_cy_set		get_cy_discriminant(t_cy *obj, t_ray *r)
{
	t_cy_set		cy;

	cy.delp = vec_sub(r->origin, obj->origin);
	obj->vec = vec_unit(obj->vec);
	cy.a = vec_len_squared(vec_sub(r->dir,
			vec_mul(obj->vec, vec_dot(r->dir, obj->vec))));
	cy.b = vec_dot(vec_sub(r->dir, vec_mul(obj->vec,
				vec_dot(r->dir, obj->vec))),
				vec_sub(cy.delp, vec_mul(obj->vec,
				vec_dot(cy.delp, obj->vec))));
	cy.c = vec_len_squared(vec_sub(cy.delp, vec_mul(obj->vec,
				vec_dot(cy.delp, obj->vec))))
				- obj->r * obj->r;
	cy.discriminant = cy.b * cy.b - cy.a * cy.c;
	return (cy);
}

static int			get_obj_far_hitpoint(t_cy_set *cy_set, t_ray *r, t_cy *obj)
{
	cy_set->root = (-cy_set->b + cy_set->sqrtd) / cy_set->a;
	cy_set->p = ray_at(r, cy_set->root);
	if ((cy_set->len = vec_dot(vec_sub(cy_set->p, obj->origin), obj->vec)) < 0)
		return (FALSE);
	if (cy_set->len <= obj->len)
	{
		t_ray ray = make_ray(obj->origin, obj->vec);
		cy_set->nv = vec_unit(vec_sub(cy_set->p,
				ray_at(&ray, cy_set->len)));
	}
	else
		return (FALSE);
	return (TRUE);
}

static	int			get_cy_hitpoint(t_cy_set *cy_set, t_rec *rec, t_ray *r, t_cy *obj)
{
	if (cy_set->discriminant < 0)
		return (FALSE);
	cy_set->sqrtd = sqrt(cy_set->discriminant);
	cy_set->root = (-cy_set->b - cy_set->sqrtd) / cy_set->a;
	if (cy_set->root < rec->t_min || cy_set->root > rec->t_max)
		return (FALSE);
	cy_set->p = ray_at(r, cy_set->root);
	if (!(cy_set->len = vec_dot(vec_sub(cy_set->p, obj->origin), obj->vec)))
		return (FALSE);
	if (cy_set->len <= obj->len && cy_set->len > 0)
	{
		t_ray ray = make_ray(obj->origin, obj->vec);
		cy_set->nv = vec_unit(vec_sub(cy_set->p, ray_at(&ray, cy_set->len)));
	}
	else
	{
		if (get_obj_far_hitpoint(cy_set, r, obj) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int					hit_cy(t_cy obj, t_ray r, double t_min, t_rec *rec)
{
	t_cy_set		cy_set;

	rec->t_min = t_min;
	cy_set = get_cy_discriminant(&obj, &r);
	if (get_cy_hitpoint(&cy_set, rec, &r, &obj) == FALSE)
		return (FALSE);
	get_record(rec, cy_set.root, &obj, &r);
	rec->normal = cy_set.nv;
	rec->albedo = obj.c;
	set_face_normal(&r, rec);
	rec->t_max = cy_set.root;
	return (TRUE);
}
