/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:44:24 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/07 20:19:06 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*re;
	size_t		i;
	size_t		j;
	size_t		size;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(re = (char *)malloc(size + 1)))
		return (0);
	while (s1[i] != '\0')
	{
		re[i] = s1[i];
		i++;
	}
	re[i] = '\0';
	while (s2[j] != '\0')
	{
		re[i + j] = s2[j];
		j++;
	}
	re[i + j] = '\0';
	return (re);
}
