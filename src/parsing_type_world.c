/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_type_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:53 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/14 21:57:54 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		pasing_c(char **word, t_world **world)
{
	t_cam *c;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In c, argu number ") * 0);
	}
	else
	{
		c = (t_cam *)malloc(sizeof(t_cam));
		c->look_from = save_dot(ft_split(word[1], ','));
		c->look_at = save_dot(ft_split(word[2], ','));
		if (!range_check(c->look_at, -1.0, 1.0))
			return (printf("In c->look_at, range over ") * 0);
		c->fov = ft_atod(word[3]);
		if (!range_check(vec_make(c->fov, 0.0, 0.0), 0.0, 180.0))
			return (printf("In c->fov, range over ") * 0);
		cam_set(world, c);
		world_lst_add(&((*world)->cam), lst_cre((void *)c), 1);
		free_split(word);
		return (1);
	}
	return (0);	
}

int		pasing_a(char **word, t_world **world)
{
	if (!check_word(word, 3))
	{
		free_split(word);
		return (printf("In A, argu number ") * 0);
	}
	else
	{
		(*world)->amb.r = ft_atod(word[1]);
		if (!range_check(vec_make((*world)->amb.r, 0.0, 0.0), 0.0, 1.0))
			return (printf("In A->r, range over ") * 0);
		(*world)->amb.c = save_col(ft_split(word[2], ','));
		if (!range_check((*world)->amb.c, 0.0, 1.0))
			return (printf("In A->c, range over ") * 0);
		free_split(word);
		return (1);
	}
	return (0);	
}

int		pasing_r(char **word, t_world **world)
{

	if (!check_word(word, 3))
	{
		free_split(word);
		return (printf("In R, argu number ") * 0);
	}
	if ((*world)->resolution.x >= 1 && (*world)->resolution.y >= 1)
		return (printf("R already exist ") * 0);
	else
	{
		(*world)->resolution.x = ft_atod(word[1]);
		(*world)->resolution.y = ft_atod(word[2]);
		if ((*world)->resolution.x >1920)
			(*world)->resolution.x = 1920;
		if ((*world)->resolution.y >1080)
			(*world)->resolution.y = 1080;
		free_split(word);
		return (1);
	}
	return (0);
}

int		pasing_l(char **word, t_world **world)
{
	t_light *l;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In l, argu number ") * 0);
	}
	else
	{
		l = (t_light *)malloc(sizeof(t_light));
		l->origin = save_dot(ft_split(word[1], ','));
		l->r = ft_atod(word[2]);
		if (!range_check(vec_make(l->r, 0.0, 0.0), 0.0, 1.0))
			return (printf("In l->r, range over") * 0);
		l->c = save_col(ft_split(word[3], ','));
		if (!range_check(l->c, 0.0, 1.0))
			return (printf("In l->c, range over") * 0);
		world_lst_add(&((*world)->light), lst_cre((void *)l), 1);
		free_split(word);
		return (1);
	}
	return (0);	
}