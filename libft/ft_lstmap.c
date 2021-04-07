/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:27:55 by hyopark           #+#    #+#             */
/*   Updated: 2020/10/28 17:34:48 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *re;
	t_list *nod;

	re = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		nod = ft_lstnew((*f)(lst->content));
		if (!nod)
		{
			ft_lstclear(&re, del);
			return (NULL);
		}
		ft_lstadd_back(&re, nod);
		lst = lst->next;
	}
	return (re);
}
