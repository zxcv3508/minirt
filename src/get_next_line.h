/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:58:26 by hyopark           #+#    #+#             */
/*   Updated: 2021/01/30 21:27:13 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
#define BUFFER_SIZE 10
int			get_next_line(int fd, char **line);

char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_strdup(const char *s1);

#endif
