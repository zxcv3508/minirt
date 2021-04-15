/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util_save.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:57 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:31:14 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		save_col(char **splited)
{
	t_color re;

	re.x = (double)ft_atoi(splited[0]) / 255.0;
	re.y = (double)ft_atoi(splited[1]) / 255.0;
	re.z = (double)ft_atoi(splited[2]) / 255.0;
	free_split(splited);
	return (re);
}

t_point		save_dot(char **splited)
{
	t_point re;

	re.x = ft_atod(splited[0]);
	re.y = ft_atod(splited[1]);
	re.y *= -1;
	re.z = ft_atod(splited[2]);
	free_split(splited);
	return (re);
}

void		world_lst_add(t_lst **lst, t_lst *new, int type)
{
	t_lst *last;

	new->type = type;
	if (!(*lst))
		*lst = new;
	last = lstlast(*lst);
	last->next = new;
	new->next = NULL;
}

static	int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

double		ft_atod(const char *s)
{
	char		**data;
	double		result;
	int			sign;
	int			i[2];
	int			decimal_len;

	if (!s)
		return (0);
	while (ft_isspace(*s) == 1)
		++s;
	sign = (*s == '-') ? -1 : 1;
	data = ft_split(s, '.');
	i[0] = ft_atoi(data[0]);
	if (data[1] == NULL)
		return ((double)i[0]);
	else
	{
		decimal_len = ft_strlen(data[1]);
		i[1] = ft_atoi(data[1]);
		if (sign == 1)
			result = (double)i[0] + (double)i[1] * pow(0.1, decimal_len);
		else
			result = (double)i[0] - (double)i[1] * pow(0.1, decimal_len);
	}
	return (result);
}
