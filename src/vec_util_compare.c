/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util_compare.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:30:56 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:26:32 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_max(t_vec v1, t_vec v2)
{
	t_vec re;

	if (v1.x < v2.x)
		re.x = v2.x;
	else
		re.x = v1.x;
	if (v1.y < v2.y)
		re.y = v2.y;
	else
		re.y = v1.y;
	if (v1.z < v2.z)
		re.z = v2.z;
	else
		re.z = v1.z;
	return (re);
}

t_vec	vec_min(t_vec v1, t_vec v2)
{
	t_vec re;

	if (v1.x > v2.x)
		re.x = v2.x;
	else
		re.x = v1.x;
	if (v1.y > v2.y)
		re.y = v2.y;
	else
		re.y = v1.y;
	if (v1.z > v2.z)
		re.z = v2.z;
	else
		re.z = v1.z;
	return (re);
}
