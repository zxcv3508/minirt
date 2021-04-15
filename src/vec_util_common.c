/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:17 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 12:41:55 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_len_squared(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_size(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec	vec_make(double x, double y, double z)
{
	t_vec re;

	re.x = x;
	re.y = y;
	re.z = z;
	return (re);
}

t_vec	vec_unit(t_vec v)
{
	double	dir;
	t_vec	re;

	dir = vec_size(v);
	re.x = v.x / dir;
	re.y = v.y / dir;
	re.z = v.z / dir;
	return (re);
}
