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
