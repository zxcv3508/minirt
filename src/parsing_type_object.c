/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_type_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:52 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:00:05 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		pasing_sp(char **word, t_world **world)
{
	t_sp *sp;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In sp, arg number ") * 0);
	}
	else
	{
		sp = (t_sp *)malloc(sizeof(t_sp));
		sp->origin = save_dot(ft_split(word[1], ','));
		sp->r = ft_atod(word[2]) / 2.0;
		sp->c = save_col(ft_split(word[3], ','));
		if (!range_check(sp->c, 0.0, 1.0))
			return (printf("In sp->c, range over ") * 0);
		world_lst_add(&((*world)->object), lst_cre((void *)sp), 1);
		free_split(word);
		return (1);
	}
	return (0);
}

int		pasing_tr(char **word, t_world **world)
{
	t_tr *tr;

	if (!check_word(word, 5))
	{
		free_split(word);
		return (printf("In tr, arg number ") * 0);
	}
	else
	{
		tr = (t_tr *)malloc(sizeof(t_tr));
		tr->p1 = save_dot(ft_split(word[1], ','));
		tr->p2 = save_dot(ft_split(word[2], ','));
		tr->p3 = save_dot(ft_split(word[3], ','));
		tr->c = save_col(ft_split(word[4], ','));
		if (!range_check(tr->c, 0.0, 1.0))
			return (printf("In tr->c, range over ") * 0);
		world_lst_add(&((*world)->object), lst_cre((void *)tr), 3);
		free_split(word);
		return (1);
	}
	return (0);
}

int		pasing_sq(char **word, t_world **world)
{
	t_sq *sq;

	if (!check_word(word, 5))
	{
		free_split(word);
		return (printf("In sq, arg number ") * 0);
	}
	else
	{
		sq = (t_sq *)malloc(sizeof(t_sq));
		sq->origin = save_dot(ft_split(word[1], ','));
		sq->nv = save_dot(ft_split(word[2], ','));
		if (!range_check(sq->nv, -1.0, 1.0))
			return (printf("In sq->nv, range over ") * 0);
		sq->r = ft_atod(word[3]);
		sq->c = save_col(ft_split(word[4], ','));
		if (!range_check(sq->c, 0.0, 1.0))
			exit(printf("In sq->c, range over ") * 0);
		world_lst_add(&((*world)->object), lst_cre((void *)sq), 4);
		free_split(word);
		return (1);
	}
	return (0);
}

int		pasing_pl(char **word, t_world **world)
{
	t_pl *pl;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In pl, argu number ") * 0);
	}
	else
	{
		pl = (t_pl *)malloc(sizeof(t_pl));
		pl->origin = save_dot(ft_split(word[1], ','));
		pl->nv = save_dot(ft_split(word[2], ','));
		if (!range_check(pl->nv, -1.0, 1.0))
			return (printf("In pl->nv, range over ") * 0);
		pl->c = save_col(ft_split(word[3], ','));
		if (!range_check(pl->c, 0.0, 1.0))
			return (printf("In pl->c, range over ") * 0);
		world_lst_add(&((*world)->object), lst_cre((void *)pl), 2);
		free_split(word);
		return (1);
	}
	return (0);
}

int		pasing_cy(char **word, t_world **world)
{
	t_cy *cy;

	if (!check_word(word, 6))
	{
		free_split(word);
		return (printf("In cy, some ") * 0);
	}
	else
	{
		cy = (t_cy *)malloc(sizeof(t_cy));
		cy->origin = save_dot(ft_split(word[1], ','));
		cy->vec = save_dot(ft_split(word[2], ','));
		if (!range_check(cy->vec, -1.0, 1.0))
			return (printf("In cy->vec, range over ") * 0);
		cy->r = ft_atod(word[3]);
		cy->len = ft_atod(word[4]);
		cy->c = save_col(ft_split(word[5], ','));
		if (!range_check(cy->c, 0.0, 1.0))
			return (printf("In cy->c, range over ") * 0);
		world_lst_add(&((*world)->object), lst_cre((void *)cy), 5);
		free_split(word);
		return (1);
	}
	return (0);
}
