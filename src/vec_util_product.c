/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:30:57 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:27:55 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_dot(t_vec v1, t_vec v2)
{
	double re;

	re = v1.x * v2.x
		+ v1.y * v2.y
			+ v1.z * v2.z;
	return (re);
}

t_vec	vec_cro(t_vec v1, t_vec v2)
{
	t_vec re;

	re.x = v1.y * v2.z - v2.y * v1.z;
	re.y = v1.z * v2.x - v2.z * v1.x;
	re.z = v1.x * v2.y - v2.x * v1.y;
	return (re);
}
