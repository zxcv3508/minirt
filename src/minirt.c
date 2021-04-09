/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:58:07 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/09 19:42:03 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int		make_rgb(t_color col)
// {
// 	int rgb;

// 	rgb = (int)col.b + ((int)col.g << 8) + ((int)col.r << 16);
// 	return (rgb);
// }

// t_color	rgb_to_col(int	rgb)
// {
// 	t_color re;

// 	re.r = (rgb & (255 << 16)) >> 16;
// 	re.g = (rgb & (255 << 8)) >> 8;
// 	re.b = rgb & 255;
// 	return (re);
// }

// t_color	col_mul(t_color c, double r)
// {
// 	if (r > 1.0)
// 		r = 1.0;
// 	c.r *= r;
// 	c.g *= r;
// 	c.b *= r;
// 	return (c);
// }

// double	col_plu(t_color c1, t_color c2)
// {
// 	c1.r += c2.r;
// 	if(c1.r > 255)
// 		c1.r = 255;
// 	c1.g += c2.g;
// 	if(c1.g > 255)
// 		c1.g = 255;
// 	c1.b += c2.b;
// 	if(c1.b > 255)
// 		c1.b = 255;
// 	return (make_rgb(c1));
// }


// int		color(double r, double g, double b)
// {
// 	t_color	col;

// 	col.r = r * 255.99;
// 	col.g = g * 255.99;
// 	col.b = b * 255.99;
// 	return (make_rgb(col));
// }

int	range_check(t_vec v, double min, double max)
{
	if ((v.x >= min && v.x <= max) && (v.y >= min && v.y <= max) && (v.z <= min && v.z <=max))
		return (0);
	else
		return (0);
}














