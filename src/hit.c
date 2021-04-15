/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:43 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:43:54 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		hit(t_lst *obj_l, t_ray primary_ray, t_rec *rec)
{
	int		is_hit;
	t_lst	*tmp_obj;

	tmp_obj = obj_l;
	is_hit = 0;
	while (tmp_obj)
	{
		is_hit += hit_type(tmp_obj, primary_ray, rec);
		tmp_obj = tmp_obj->next;
	}
	return (is_hit);
}

int		hit_type(t_lst *lst, t_ray r, t_rec *rec)
{
	if (lst->type == SP)
		return (hit_sph(*((t_sp *)lst->obj), r, 0, rec));
	if (lst->type == PL)
		return (hit_pl(*((t_pl *)(lst->obj)), r, 0, rec));
	if (lst->type == TR)
		return (hit_tr(*((t_tr *)(lst->obj)), r, 0, rec));
	if (lst->type == SQ)
		return (hit_sq(*((t_sq *)(lst->obj)), r, 0, rec));
	if (lst->type == CY)
		return (hit_cy(*((t_cy *)(lst->obj)), r, 0, rec));
	return (0);
}
