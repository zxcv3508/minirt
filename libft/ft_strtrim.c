/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:13:05 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/27 16:05:20 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		rfind_set(char const *s1, char const *set)
{
	size_t i;

	if (!*s1)
		return (0);
	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (ft_strchr(set, s1[i]))
		{
			if (i == 0)
				return (i);
			i--;
		}
		else
			return (i);
	}
	return (i);
}

static size_t		find_set(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	if (!*s1)
		return (0);
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			return (i);
	}
	return (i);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*re;
	size_t	s;
	size_t	e;
	size_t	i;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	s = find_set(s1, set);
	e = rfind_set(s1, set);
	if (e < s || s >= (ft_strlen(s1) - 1) || e == 0)
		return (ft_strdup(""));
	re = (char *)malloc(sizeof(char) * (e - s) + 2);
	if (!re)
		return (0);
	i = 0;
	while (s <= e)
	{
		re[i] = s1[s];
		s++;
		i++;
	}
	re[i] = '\0';
	return (re);
}
