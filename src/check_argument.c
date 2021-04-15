/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:57:28 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/15 13:42:41 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_argument(int ac, char **av)
{
	if (ac <= 1 || ac > 3)
		return (printf("arg num error") * 0);
	if (ac == 3)
	{
		if (!ft_strnstr(av[2], "--save", 6))
			return (printf("3arg error") * 0);
	}
	if (!ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3))
		return (1);
	else
		printf("not .rt file");
	return (0);
}
