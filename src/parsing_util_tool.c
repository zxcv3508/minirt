/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:58:00 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 12:51:47 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		range_check(t_vec v, double min, double max)
{
	if ((v.x >= min && v.x <= max) && (v.y >= min && v.y <= max) &&
		(v.z >= min && v.z <= max))
		return (1);
	else
		return (0);
}

t_lst	*lst_cre(void *obj)
{
	t_lst	*re;

	re = (t_lst *)malloc(sizeof(t_lst));
	if (!re)
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
		lst = lst->next;
	return (lst);
}

int		check_word(char **word, int n)
{
	int	i;

	i = 0;
	while (word[i])
		i++;
	if (i == n)
		return (1);
	else
		return (0);
}
