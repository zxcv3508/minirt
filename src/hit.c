#include "minirt.h"

int	hit_type(t_lst *lst, t_ray r, t_rec *rec)
{
 	if (lst->type == SP)
		return (hit_sph(*((t_sp *)lst->obj),r,0,rec));
	// if (lst->type == PL)
	// 	return (hit_pl(*((t_pl *)(lst->obj)),r,0,rec));
/* 	if (lst->type == TR)
		return (hit_tr(*((t_pl *)(lst->obj)),r,0,0xffffff,rec));i */
// 	if (lst->type == SQ)
//		return (hit_sq(*((t_sq *)(lst->obj)),r,0,0xffffff,rec));/*
// 	if (lst->type == SY)
//		return (hit_sy(*((t_pl *)(lst->obj)),r,0,0xffffff,rec));
	return (0);
}
