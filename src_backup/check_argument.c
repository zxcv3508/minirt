#include "minirt.h"

// void		check_argument(int argc, char *argv[])
// {
// 	int		len;

// 	if (argc != 2 && argc != 3)
// 	{
// 		printf("number of argument shoud be 2 or 3\n");
// 		exit (1);
// 	}
// 	else if (argc == 3)
// 	{
// 		if (ft_strncmp(argv[2], "--save", 7))
// 			exit(1);
// 	}
// 	else
// 	{
// 		len = ft_strlen(argv[1]);
// 		if (ft_strncmp(argv[1] + len - 4, ".rt", 4))
// 			exit(1);
// 	}
	
// }

int		check_argument(int ac, char **av)
{
	if (ac <= 1 || ac >3)
		return (printf("arg num error") * 0);
	if (ac == 3)
	{
		if(!ft_strnstr(av[2], "--save", 6))
			return (printf("3arg error") * 0);
	}
	if (!ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3))
		return (1);
	else
		printf("not .rt file");
	return (0);
}

