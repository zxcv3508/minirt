#include "minirt.h"

 t_ray	make_shadow_ray(t_ray primary_ray, t_light *light, t_rec *rec)
 {
	t_ray	shadow_ray;

	shadow_ray.origin = vec_plu(rec->p, vec_mul(rec->normal, 0.000001));
	shadow_ray.dir = vec_sub((light->origin), (rec->p));
	light->len = vec_size(shadow_ray.dir);
	shadow_ray.dir = vec_unit(shadow_ray.dir);
	return (shadow_ray);
}
int		in_shadow(t_lst *obj_list, t_ray shadow_ray, t_light *light)
{	
	t_rec	shadow_rec;

	//rec_init(&shadow_rec);
	shadow_rec.t_max = light->len;// 빛의 최대거리제한 = 히트포인트에서 빛의 원점까지
	int a = (hit(obj_list, shadow_ray, &shadow_rec))	;
	
	//printf("in_shadow is_hit : %d\n", a);
	//	if(hit(obj_list, shadow_ray, &shadow_rec))
	if(a)
		return (1);
	else
		return (0);	
}

t_color		get_phong_light_from(t_world *world, t_ray primary_ray, t_rec *rec, t_light *light)
{
	t_color	specular;
	t_color	diffuse;
	
	rec->t_max = 99999.0;
	if (in_shadow(world->object, make_shadow_ray(primary_ray, light, rec), light))
	 	return (vec_make(0,0,0));
	 else
	{
		specular = make_spec(primary_ray, rec, light);
		diffuse = make_diffuse(primary_ray, rec, light);
	//	printf("s : %f, d : %f\n", specular.z,diffuse.z);
		return (vec_plu(specular, diffuse));
	}
}

t_color		get_phong_color(t_world *world, t_ray primary_ray, t_rec *rec)
{
	t_color		light_color;
	t_lst	*light_list = (world->light);
		
	light_color = vec_make(0,0,0);
	while (light_list)
	{
		light_color = vec_plu(light_color, get_phong_light_from(world, primary_ray, rec, (t_light *)(light_list->obj)));
		light_list = light_list->next;
	}
	light_color = vec_plu(light_color, vec_mul(world->amb.c, world->amb.r)); //global_ambient;??? +? *?
	//		printf("lihihtcol : %f,%f,%f\n", light_color.x,light_color.y,light_color.z);
	return (vec_min(vec_pow(light_color, rec->albedo), vec_make(1.0, 1.0, 1.0)));
}

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

void	rec_init(t_rec *rec)
{
	rec->t_min = 0.000001;
	rec->t_max = 999999.0;
}

t_color		ray_get_color(t_world *world,t_ray primary_ray)
{
	t_color		pixel_color;
	t_rec		rec;

	rec_init(&rec);
	pixel_color = vec_make(0,0,0);
	if (hit(world->object, primary_ray, &rec))//rec-> col : closest hit color 
	{
		pixel_color = vec_pow(rec.albedo, get_phong_color(world, primary_ray, &rec));
	//	printf("phongcol : %f,%f,%f\n", get_phong_color(world, primary_ray, &rec).x,get_phong_color(world, primary_ray, &rec).y,get_phong_color(world, primary_ray, &rec).z);
	}
	else
		pixel_color = vec_make(0.0,1.0,0.0);//get_background_color();//if non-hit : 0,0,0 
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