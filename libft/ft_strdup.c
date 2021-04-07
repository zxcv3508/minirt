/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:56:47 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/20 15:37:50 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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
