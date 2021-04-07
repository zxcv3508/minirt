/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:16:25 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/20 15:40:11 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (0);
	while (i < size)
	{
		if (src[i] == '\0')
		{
			dest[i] = '\0';
			return (ft_strlen(src));
		}
		else if (i == (size - 1))
		{
			dest[i] = '\0';
			return (ft_strlen(src));
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (ft_strlen(src));
}
