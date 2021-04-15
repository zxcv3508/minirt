/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util_calculations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:30:55 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:25:35 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_pow(t_vec d1, t_vec d2)
{
	t_vec re;

	re.x = d1.x * d2.x;
	re.y = d1.y * d2.y;
	re.z = d1.z * d2.z;
	return (re);
}

t_vec	vec_mul(t_vec v, double r)
{
	t_vec re;

	re.x = v.x * r;
	re.y = v.y * r;
	re.z = v.z * r;
	return (re);
}

t_vec	vec_plu(t_vec v1, t_vec v2)
{
	t_vec re;

	re.x = v1.x + v2.x;
	re.y = v1.y + v2.y;
	re.z = v1.z + v2.z;
	return (re);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}
