/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:03:10 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/26 15:27:06 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*re;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	re = (char *)malloc(sizeof(char) * len + 1);
	if (!re)
		return (0);
	if (start >= ft_strlen(s))
		return (0);
	while (i < len)
		re[i++] = s[start++];
	re[i] = '\0';
	return (re);
}
