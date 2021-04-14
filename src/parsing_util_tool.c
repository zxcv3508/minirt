/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:00 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:58:01 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	range_check(t_vec v, double min, double max)
{
	if ((v.x >= min && v.x <= max) && (v.y >= min && v.y <= max) && (v.z >= min && v.z <=max))
		return (1);
	else
		return (0);
}

static	int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

double			ft_atod(const char *s)
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

t_lst	*lst_cre(void *obj)
{
	t_lst	*re;
	
	re = (t_lst *)malloc(sizeof(t_lst));
	if(!re)
		return (0);
	re->obj = obj;
	re->next = NULL;
	return (re);
}

t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
int		check_word(char **word, int n)
{
	int i;

	i = 0;
	while (word[i])
		i++;
	if (i == n)
		return(1);
	else
		return (0);
}