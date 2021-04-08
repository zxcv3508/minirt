#include "minirt.h"

/*
intcheck_world(t_world *world)
{
	
}
*/

int		pasing_format_check(char *line, t_world **world)
{
	char **word;

	if (!*line)
		return (1);
	word = ft_split(line,' ');
	if(!ft_strncmp(*word,"R",1))
		return(pasing_r(word, world));
	else if(!ft_strncmp(*word,"A",1))
		return(pasing_a(word, world));
	else if(!ft_strncmp(*word,"cy",2))
		return(pasing_cy(word, world));
	else if(!ft_strncmp(*word,"c",1))
		return(pasing_c(word, world));
	else if(!ft_strncmp(*word,"l",1))
		return(pasing_l(word, world));
	else if(!ft_strncmp(*word,"sp",2))
		return(pasing_sp(word, world));
	else if(!ft_strncmp(*word,"pl",2))
		return(pasing_pl(word, world));
	else if(!ft_strncmp(*word,"sq",2))
		return(pasing_sq(word, world));
	else if(!ft_strncmp(*word,"tr",2))
		return(pasing_tr(word, world));
	free_split(word);
	return (printf("wrong init ") * 0);
}

int		pas_world(int fd, int is_save)
{
	char	*line;
	t_world	*world;

	if (fd < 3)
		return (printf("opne ") * 0);
	world = init_world();
	while (get_next_line(fd, &line))
	{
		if(!pasing_format_check(line, &world))
			return(0);
		free(line);
	}
	//check_world(&world);
	make_world(&world, is_save);
	free(line);
	free_world(world);
	return (1);
}