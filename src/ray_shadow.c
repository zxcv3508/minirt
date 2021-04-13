#include "minirt.h"

int		in_shadow(t_lst *obj_list, t_ray shadow_ray, t_light *light, t_rec *rec)
{	
	t_rec	shadow_rec;

	//rec_init(&shadow_rec);
	shadow_rec.t_max = light->len;// 빛의 최대거리제한 = 히트포인트에서 빛의 원점까지
	int a = (hit(obj_list, shadow_ray, &shadow_rec));
	
	//printf("in_shadow is_hit : %d\n", a);
	//	if(hit(obj_list, shadow_ray, &shadow_rec))
	if(a || vec_dot(rec->normal, shadow_ray.dir) < 0.0)
	{
		// printf("pareallasla\n");
		return (1);
	}
	else
		return (0);	
}