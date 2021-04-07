/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:57:56 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/20 15:38:47 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	tmp;
	int		token;

	i = 0;
	token = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			tmp = i;
			token += 1;
		}
		i++;
	}
	if (token != 0)
		return ((char *)s + tmp);
	else if (c == '\0')
		return ((char *)s + ft_strlen(s));
	else
		return (0);
}
