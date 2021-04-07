/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:15:59 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/28 16:24:07 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	str_l;
	size_t	to_find_l;
	size_t	size;

	if (*to_find == '\0')
		return ((char *)str);
	str_l = ft_strlen(str);
	to_find_l = ft_strlen(to_find);
	if (str_l < to_find_l || len < to_find_l)
		return (0);
	if (str_l > len)
		size = len;
	else
		size = str_l;
	while (size-- >= to_find_l)
	{
		if (ft_memcmp(str, to_find, to_find_l) == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
