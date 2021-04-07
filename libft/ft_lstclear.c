/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:17:47 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/26 18:48:53 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *nod;
	t_list *next;

	nod = *lst;
	while (nod)
	{
		next = nod->next;
		ft_lstdelone(nod, del);
		nod = next;
	}
	*lst = 0;
	free(*lst);
}
