#include "minirt.h"

 t_ray	make_shadow_ray(t_ray primary_ray, t_light *light, t_rec *rec)
 {
	t_ray	shadow_ray;

	shadow_ray.origin = rec->p;
	shadow_ray.dir = vec_sub((light->origin), (rec->p));
	return (shadow_ray);
}
int		in_shaodw(t_lst *obj_list, t_ray shadow_ray)
{	
	t_rec	shadow_rec;

	if(hit(obj_list, shadow_ray, &shadow_rec))
		return (1);
	else
		return (0);	
}

t_color		get_phong_light_from(t_world *world, t_ray primary_ray, t_rec *rec, t_light *light)
{
	t_color	specular;
	t_color	diffuse;
	
	if (in_shaodw(world->object, make_shadow_ray(primary_ray, light, rec)))
	 	return (vec_make(0,0,0));
	 else
	{
		specular = make_spec(primary_ray, rec, light);
		diffuse = make_diffuse(primary_ray, rec, light);
		return (vec_plu(specular, diffuse));
	}
}

t_color		get_phong_color(t_world *world, t_ray primary_ray, t_rec *rec)
{
	t_color		light_color;
	t_lst	*light_list = (world->light);
 	t_light *light =(t_light *)(world->light->obj);
		
	light_color = vec_make(0,0,0);
	while (light_list)
	{
		light_color = vec_plu(light_color, get_phong_light_from(world, primary_ray, rec, light));
		light_list = light_list->next;
	}
	light_color = vec_plu(light_color, vec_mul(world->amb.c, world->amb.r)); //global_ambient;??? +? *?
	return (vec_min(vec_pow(light_color, rec->albedo), vec_make(1.0, 1.0, 1.0)));
}

int 	hit(t_lst *obj_l, t_ray primary_ray, t_rec *rec)
{
	int is_hit;
	
	rec->t_max = 999.0;
	while(obj_l)
	{
		is_hit = hit_type(obj_l, primary_ray, rec);
		obj_l = obj_l->next;
	}
	if (is_hit)
		return (1);
	else
		return (0);
}



t_color		ray_get_color(t_world *world,t_ray primary_ray)
{
	t_color		pixel_color;
	t_rec		*rec;

	pixel_color = vec_make(0,0,0);
	if (hit(world->object, primary_ray, rec))
		vec_pow(pixel_color, get_phong_color(world, primary_ray, rec));
	else
		pixel_color = vec_make(0.0,0.0,0.0);//get_background_color();
		
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