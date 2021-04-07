/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:16:33 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/27 15:59:35 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_c(char const *s, char c)
{
	int i;
	int re;

	i = 0;
	re = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			re++;
		}
		if (s[i])
			i++;
	}
	return (re);
}

static void		ft_put_split(char const *s, char **re, int k, int j)
{
	int		i;

	i = 0;
	while (k < j && s[k])
	{
		(*re)[i] = s[k];
		k++;
		i++;
	}
	(*re)[i] = '\0';
}

static char		**ft_freee(char **re)
{
	int		i;

	i = 0;
	while (re[i])
	{
		free(re[i]);
		i++;
	}
	free(re);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**re;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s || !(re = (char **)malloc(sizeof(char *) * (ft_find_c(s, c) + 1))))
		return (0);
	while (i < ft_find_c(s, c) && (size_t)k < ft_strlen(s) && s[k])
	{
		while (s[k] == c && s[k])
			k++;
		j = k;
		while (s[j] != c && s[j])
			j++;
		if (!(re[i] = (char *)malloc(sizeof(char) * (j - k) + 1)))
			return (ft_freee(re));
		ft_put_split(s, &re[i], k, j);
		k = j;
		i++;
	}
	re[i] = 0;
	return (re);
}
