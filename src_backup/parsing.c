#include "minirt.h"

t_bool		parse_a_line(char *line, t_world **world)
{
	char	**word;

	if (!*line)
		return (1);
	word = ft_split(line,' ');
	if (!ft_strncmp(*word, "R", 1))
		return (pasing_r(word, world));
	else if (!ft_strncmp(*word, "A", 1))
		return (pasing_a(word, world));
	else if (!ft_strncmp(*word, "cy", 2))
		return (pasing_cy(word, world));
	else if (!ft_strncmp(*word, "c", 1))
		return (pasing_c(word, world));
	else if (!ft_strncmp(*word, "l", 1))
		return (pasing_l(word, world));
	else if (!ft_strncmp(*word, "sp", 2))
		return (pasing_sp(word, world));
	else if (!ft_strncmp(*word, "pl", 2))
		return (pasing_pl(word, world));
	else if (!ft_strncmp(*word, "sq", 2))
		return (pasing_sq(word, world));
	else if (!ft_strncmp(*word, "tr", 2))
		return (pasing_tr(word, world));
	free_split(word);
	return (printf("wrong init ") * 0);
}

void		parse_world(t_world **world, char *argv[])
{
	char	*line;
	int		fd;
	int		gnl_return;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if(!parse_a_line(line, world))
			break ;
		free(line);
	}
	(*world)->camera_head = (*world)->cam;
	free(line);
}