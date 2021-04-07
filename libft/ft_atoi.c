/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:57:44 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/25 15:33:43 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	re;
	int			si;
	int			i;

	si = 1;
	re = 0;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
	{
		i++;
	}
	if (str[i] == '-')
	{
		si *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		re *= 10;
		re += str[i] - '0';
		i++;
	}
	return (re * si);
}
