/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:33:31 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/27 15:55:36 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		i_mod(int n)
{
	while (n > 9)
		n %= 10;
	return (n);
}

static int		i_abs(int n)
{
	if (n == 0)
		return (0);
	else if (n < 0)
		return (n * -1);
	else
		return (n);
}

static int		ft_check_le(int n)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = n;
	if (tmp < 0)
	{
		tmp *= 1;
		i++;
	}
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*re;

	i = 1;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_check_le(n);
	tmp = n;
	n = i_abs(n);
	re = (char *)malloc(sizeof(char) * i + 1);
	if (!re)
		return (0);
	re[i] = '\0';
	while (--i >= 0)
	{
		re[i] = i_mod(n) + '0';
		n /= 10;
	}
	if (tmp < 0)
		re[0] = '-';
	return (re);
}
