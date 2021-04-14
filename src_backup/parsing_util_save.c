#include "minirt.h"

t_color	save_col(char **splited)
{
	t_color re;

	re.x = (double)ft_atoi(splited[0]) / 255.0;
	re.y = (double)ft_atoi(splited[1]) / 255.0;
	re.z = (double)ft_atoi(splited[2]) / 255.0;
	free_split(splited);
	return (re);
}

t_point	save_dot(char **splited)
{
	t_point re;

	re.x = ft_atod(splited[0]);
	re.y = ft_atod(splited[1]);
	re.z = ft_atod(splited[2]);
	free_split(splited);
	return (re);
}

void	world_lst_add(t_lst **lst, t_lst *new, int type)
{
	t_lst *last;

	new->type = type;
	if (!(*lst))
		*lst = new;
	last = lstlast(*lst); 
	last->next = new;
	new->next = NULL;
}