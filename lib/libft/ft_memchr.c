/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:49:50 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/20 15:35:56 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int v, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (a[i] == (unsigned char)v)
			return (a + i);
		i++;
	}
	return (0);
}
