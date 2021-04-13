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
		c->look_from = save_dot(ft_split(word[1], ','));
		c->look_at = save_dot(ft_split(word[2], ','));
		c->fov = ft_atod(word[3]);
		cam_set(world, c);
		world_lst_add(&((*world)->cam), lst_cre((void *)c), 1);
		free_split(word);
		// if (range_check(c->look_at, -1.0, 1.0))
		// 	return (printf("range over") * 0);
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
		(*world)->amb.r = ft_atod(word[1]);
		(*world)->amb.c = save_col(ft_split(word[2], ','));
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
	if ((*world)->resolution.x >= 1 && (*world)->resolution.y >= 1)
	{
		printf("%f,%f\n", (*world)->resolution.x, (*world)->resolution.y);
		return (printf("R already exist ") * 0);
	}
	else
	{
		(*world)->resolution.x = ft_atod(word[1]);
		(*world)->resolution.y = ft_atod(word[2]);
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
		return (printf("In l, some ") * 0);
	}
	else
	{
		l = (t_light *)malloc(sizeof(t_light));
		l->origin = save_dot(ft_split(word[1], ','));
		l->r = ft_atod(word[2]);
		l->c = save_col(ft_split(word[3], ','));
		world_lst_add(&((*world)->light), lst_cre((void *)l), 1);
		free_split(word);
		return (1);
	}
	return (0);	
}