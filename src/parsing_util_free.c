/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:55 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:57:56 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	lst_free(t_lst **lst)
{
	t_lst *nod;
	t_lst *next;

	nod = *lst;
	while (nod)
	{
		next = nod->next;
		free(nod->obj);
		free(nod);
		nod = next;
	}
}

void	free_world(t_world *world)
{
	lst_free(&(world->object));
	lst_free(&(world->cam));
	lst_free(&(world->light));
	free(world);
}
