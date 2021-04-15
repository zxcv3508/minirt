/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util_trigonometric.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:30:50 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:22:15 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_cos(t_vec v1, t_vec v2)
{
	return (vec_dot(v1, v2) / (vec_size(v1) * vec_size(v2)));
}

double	vec_sin(t_vec v1, t_vec v2)
{
	return (vec_size(vec_cro(v1, v2)) / (vec_size(v1) * vec_size(v2)));
}
