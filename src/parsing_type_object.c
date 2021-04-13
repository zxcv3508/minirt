#include "minirt.h"

int		pasing_sp(char **word, t_world **world)
{
	t_sp *sp;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In sp, some ") * 0);
	}
	else
	{
		sp = (t_sp *)malloc(sizeof(t_sp));
		sp->origin = save_dot(ft_split(word[1], ','));
		sp->r = ft_atod(word[2]);
		sp->c = save_col(ft_split(word[3], ','));
		//if (!(range_check(sp->c.r, 0, 255) && range_check(sp->c.g, 0, 255) && range_check(sp->c.b, 0, 255) ))
		//	return (printf("color ") * 0);
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
		return (printf("In tr, some ") * 0);
	}
	else
	{
		tr = (t_tr *)malloc(sizeof(t_tr));
		tr->p1 = save_dot(ft_split(word[1], ','));
		tr->p2 = save_dot(ft_split(word[2], ','));
		tr->p3 = save_dot(ft_split(word[3], ','));
		tr->c = save_col(ft_split(word[4], ','));
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
		return (printf("In sq, some ") * 0);
	}
	else
	{
		sq = (t_sq *)malloc(sizeof(t_sq));
		sq->origin = save_dot(ft_split(word[1], ','));
		sq->nv = save_dot(ft_split(word[2], ','));
		sq->r = ft_atod(word[3]);
		sq->c = save_col(ft_split(word[4], ','));
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
		return (printf("In pl, some ") * 0);
	}
	else
	{
		pl = (t_pl *)malloc(sizeof(t_pl));
		pl->origin = save_dot(ft_split(word[1], ','));
		pl->nv = save_dot(ft_split(word[2], ','));
		pl->c = save_col(ft_split(word[3], ','));
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
		cy->nv = save_dot(ft_split(word[2], ','));
		cy->d = ft_atod(word[3]);
		cy->h = ft_atod(word[4]);
		cy->c = save_col(ft_split(word[5], ','));
		world_lst_add(&((*world)->object), lst_cre((void *)cy), 5);
		free_split(word);
		return (1);
	}
	return (0);	
}