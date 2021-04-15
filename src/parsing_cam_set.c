/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cam_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:48 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:14:02 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vup(t_vec v)
{
	v = vec_unit(v);
	if (v.x == 0.0 && v.z == 0.0)
		return (vec_unit(vec_make(0.0, v.y * 0.999999, 0.00001)));
	else
		return (vec_make(0.0, 1.0, 0.0));
}

double	make_degrees(double radians)
{
	return (radians * (M_PI / 180.0));
}

void	cam_set(t_world **world, t_cam *camera)
{
	double theta;

	theta = make_degrees(camera->fov);
	camera->view_h = 2.0 * tan(theta / 2.0);
	camera->view_w = (double)(*world)->resolution.x /
		(double)(*world)->resolution.y * (double)camera->view_h;
	camera->w = vec_unit(camera->look_at);
	camera->u = vec_unit(vec_cro(camera->w, vup(camera->w)));
	camera->v = vec_unit(vec_cro(camera->w, camera->u));
	camera->v = vec_unit(vec_cro(camera->u, camera->w));
	camera->horizontal = vec_mul(camera->u, camera->view_w);
	camera->vertical = vec_mul(camera->v, camera->view_h);
	camera->lower_left_corner = vec_plu(vec_sub(vec_sub(camera->look_from,
		vec_mul(camera->horizontal, 0.5)),
			vec_mul(camera->vertical, 0.5)), camera->w);
}
