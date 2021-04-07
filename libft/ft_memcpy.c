/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:28:18 by hyopark           #+#    #+#             */
/*   Updated: 2021/01/30 17:40:04 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (d == (void *)0 && s == (void *)0)
		return (0);
	while (i < num)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
