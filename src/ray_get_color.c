/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_get_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:06 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 12:59:31 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		ray_get_color(t_world *world, t_ray primary_ray)
{
	t_color		pixel_color;
	t_rec		rec;

	rec.t_max = 999999.0;
	pixel_color = vec_make(0, 0, 0);
	if (hit(world->object, primary_ray, &rec))
		pixel_color = vec_pow(rec.albedo,
			get_phong_color(world, primary_ray, &rec));
	else
		pixel_color = vec_make(0.0, 0.0, 0.0);
	return (pixel_color);
}

t_color		get_phong_color(t_world *world, t_ray primary_ray, t_rec *rec)
{
	t_color	light_color;
	t_lst	*light_list;

	light_list = (world->light);
	light_color = vec_make(0, 0, 0);
	while (light_list)
	{
		light_color = vec_plu(light_color, get_phong_light_from(world,
			primary_ray, rec, (t_light *)(light_list->obj)));
		light_list = light_list->next;
	}
	light_color = vec_plu(light_color, vec_mul(world->amb.c, world->amb.r));
	return (vec_min(vec_pow(light_color, rec->albedo),
		vec_make(1.0, 1.0, 1.0)));
}

t_color		get_phong_light_from(t_world *world, t_ray primary_ray,
	t_rec *rec, t_light *light)
{
	t_color	specular;
	t_color	diffuse;
	t_lst	*obj_list;

	obj_list = world->object;
	if (in_shadow(obj_list, make_shadow_ray(primary_ray,
		light, rec), light, rec))
		return (vec_make(0, 0, 0));
	else
	{
		specular = make_spec(primary_ray, rec, light);
		diffuse = make_diffuse(primary_ray, rec, light);
		return (vec_plu(specular, diffuse));
	}
}
