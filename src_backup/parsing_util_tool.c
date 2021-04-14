#include "minirt.h"

double	ft_atod(char *s)
{
	double	re;
	int	tmp;
	int	inter;

	int i;
	tmp = 0;
	i = 0;
	re = 0;
	while (s[i] != '.' && s[i])
		 i++;
	tmp = ft_atoi(s);
	if(s[i] == '.')
		i++;
	inter = tmp;
	tmp = i;
	while(s[i])
	{
		re *= 10.0;
		re += (double)(s[i] - '0');
		i++;
	}
	if (s[0] != '-')
		re = (double)inter + re / pow(10, (i - tmp));
	else
	{
		re = (double)inter - re/ pow(10,(i-tmp));
		return (1.0 * re);
	}
	return (re);
}

t_lst	*lst_cre(void *obj)
{
	t_lst	*re;
	
	re = (t_lst *)malloc(sizeof(t_lst));
	if(!re)
		return (0);
	re->obj = obj;
	re->next = NULL;
	return (re);
}

t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
int		check_word(char **word, int n)
{
	int i;

	i = 0;
	while (word[i])
		i++;
	if (i == n)
		return(1);
	else
		return (0);
}