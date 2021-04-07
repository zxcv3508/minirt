/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:24:21 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/25 15:52:39 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*re;

	i = 0;
	if (!s)
		return (0);
	re = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!re)
		return (0);
	while (s[i] != '\0')
	{
		re[i] = f(i, s[i]);
		i++;
	}
	re[i] = '\0';
	return (re);
}
