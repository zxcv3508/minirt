#include "minirt.h"

t_color		get_phong_color(t_world *world, t_ray r, t_rec *rec)
{
	t_color		light_color;
	t_lst	*l_l = (world->l);
 	t_l *light =(t_l *)(world->l->obj);
		
	light_color = color(0,0,0);
	while (light)
	{
		light_color += get_phong_light_from(primary_ray, light, rec);
		light = light->next;
	}
	light_color += global_ambient;
	return (vec_min(rec.albedo * light_color, color(1, 1, 1));
}


t_color		get_phong_light_from(t_ray primary_ray, t_rec *rec)
{
	t_color	specular;
	t_color	diffuse;
	
	make_shadowray();
	if (in_shaodw())
		return (make_color(0,0,0));
	else
	{
		specular = make_spec(primary_ray, rec, light);
		diffuse = make_diffuse();
		return (vec_plu(specular, diffuse));
	}
}

t_color		ray_get_color(t_world *world)
{
	t_color		pixel_color;

	pixel_color = color(0,0,0);
	if (hit())
		pixel_color = get_phong_color();
	else
		pixel_color = get_background_color();
	return (pixel_color);
}

// int		ray_col(t_world **world, t_ray r)
// {
// 	t_lst *obj_l;
// 	t_lst *lig_l;
// 	t_rec  rec;
// 	t_phong	p;
// 	double l;
// 	double d;
// 	double a;
// 	int pixel;

// 	rec.t_max = 999999999.0;
	
// 	rec.col = 0;
// 	a = (*world)->a.r;
// 	obj_l = (*world)->o;
// 	lig_l = (*world)->l;
// 	int t;
// 	while (obj_l != NULL)
// 	{	
// 		hit_type(obj_l, r, &rec);
// 		obj_l = obj_l->next;
// 	}
// 		t = rec.col;
// 	if (t > 0 )
// 	{
// 		rec.t_max = 999999999.0;
// 		p = trace_light(*world, r, &rec);
		
// 			printf("l :%f d : %f a : %f\n",p.s, p.d ,a);
// 		// return (col_plu(col_mul(rgb_to_col(t), a + p.d), col_mul(((t_l *)(lig_l->obj))->c, p.s)));
// //pixel = col_mul(rgb_to_col(t) , p.d + p.s);
// 		return (pixel);
// 	}
// 	return (0);
// }