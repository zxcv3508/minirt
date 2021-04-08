#include "minirt.h"

int		pasing_c(char **word, t_world **world)
{
	t_cam *c;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In c, some ") * 0);
	}
	else
	{
		c = (t_cam *)malloc(sizeof(t_cam));
		c->o = save_dot(ft_split(word[1], ','));
		c->nv = save_dot(ft_split(word[2], ','));
		c->r = ft_atod(word[3]);
		world_lst_add(&((*world)->c), lst_cre((void *)c), 1);
		cam_set();//
		free_split(word);
		if (range_check(c->nv, -1.0, 1.0))
			return (printf("range over") * 0);
		return (1);
	}
	return (0);	
}

int		pasing_a(char **word, t_world **world)
{
	if (!check_word(word, 3))
	{
		free_split(word);
		return (printf("In a, some ") * 0);
	}
	else
	{
		(*world)->a.r = ft_atod(word[1]);
		(*world)->a.c = save_col(ft_split(word[2], ','));
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
		return (printf("In R, some ") * 0);
	}
	if ((*world)->r.x >= 1 && (*world)->r.y >= 1)
	{
		printf("%f,%f\n", (*world)->r.x, (*world)->r.y);
		return (printf("R already exist ") * 0);
	}
	else
	{
		(*world)->r.x = ft_atod(word[1]);
		(*world)->r.y = ft_atod(word[2]);
		free_split(word);
		return (1);
	}
	return (0);
}

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
		world_lst_add(&((*world)->o), lst_cre((void *)sp), 1);
		free_split(word);
		return (1);
	}
	return (0);	
}

int		pasing_l(char **word, t_world **world)
{
	t_l *l;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In l, some ") * 0);
	}
	else
	{
		l = (t_l *)malloc(sizeof(t_l));
		l->o = save_dot(ft_split(word[1], ','));
		l->r = ft_atod(word[2]);
		l->c = save_col(ft_split(word[3], ','));
		world_lst_add(&((*world)->l), lst_cre((void *)l), 1);
		free_split(word);
		return (1);
	}
	return (0);	
}