/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:50:24 by hyopark           #+#    #+#             */
/*   Updated: 2021/02/24 15:52:19 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			find_ln(char **tmp, char **line, int fd)
{
	int		i;
	char	*free_p;

	i = 0;
	while (tmp[fd][i] != '\0')
	{
		if (tmp[fd][i] == '\n')
		{
			tmp[fd][i] = '\0';
			*line = ft_strdup(tmp[fd]);
			free_p = ft_strdup(&tmp[fd][i + 1]);
			free(tmp[fd]);
			tmp[fd] = free_p;
			return (1);
		}
		i++;
	}
	return (-1);
}

int			return_tmp(int fd, char **line, char **tmp)
{
	if (tmp[fd])
	{
		if (find_ln(tmp, line, fd) >= 0)
			return (1);
		*line = ft_strdup(tmp[fd]);
		free(tmp[fd]);
		tmp[fd] = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*tmp[OPEN_MAX];
	int				read_i;
	char			*free_p;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_i] = '\0';
		free_p = tmp[fd];
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		free(free_p);
		if (find_ln(tmp, line, fd) >= 0)
			return (1);
	}
	if (read_i < 0)
		return (-1);
	return (return_tmp(fd, line, tmp));
}
