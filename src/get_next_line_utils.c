/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:31:54 by hyopark           #+#    #+#             */
/*   Updated: 2020/11/07 14:30:21 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char			*ft_strdup(const char *s1)
{
	char	*re;
	size_t	i;

	i = 0;
	re = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!re)
		return (0);
	while (s1[i] != '\0')
	{
		re[i] = s1[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*re;
	size_t		i;
	size_t		j;
	size_t		size;

	i = -1;
	j = 0;
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(re = (char *)malloc(size + 1)))
		return (0);
	while (s1[++i] != '\0')
		re[i] = s1[i];
	re[i] = '\0';
	while (s2[j] != '\0')
	{
		re[i + j] = s2[j];
		j++;
	}
	re[i + j] = '\0';
	return (re);
}
