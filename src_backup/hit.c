#include "minirt.h"

int 	hit(t_lst *obj_l, t_ray primary_ray, t_rec *rec)
{
	int is_hit;
	t_lst *tmp_obj;

	tmp_obj = obj_l;
	is_hit = 0;
	while(tmp_obj)
	{	
		is_hit += hit_type(tmp_obj, primary_ray, rec);
		tmp_obj = tmp_obj->next;
	}
	//printf("is_hit in hit : %d\n", is_hit);
	return(is_hit);
}

int	hit_type(t_lst *lst, t_ray r, t_rec *rec)
{
 	if (lst->type == SP)
		return (hit_sph(*((t_sp *)lst->obj), r, 0, rec));
	if (lst->type == PL)
		return (hit_pl(*((t_pl *)(lst->obj)), r, 0, rec));
	if (lst->type == TR)
		return (hit_tr(*((t_tr *)(lst->obj)), r, 0, rec));
	if (lst->type == SQ)
		return (hit_sq(*((t_sq *)(lst->obj)), r, 0, rec));
	// if (lst->type == SY)
	// 	return (hit_sy(*((t_cy *)(lst->obj)), r, 0, rec));
	return (0);
}