#include "minirt.h"

int	main(int ac, char **av)
{
	int	save;

	if (ac <= 1 || ac >3)
		return (printf("arg num error") * 0);
	if (ac == 3)
	{
		if(ft_strnstr(av[2], "--save", 6))
			save = 1;
		else
			return (printf("3arg error") * 0);
	}
	if (!ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3))
	{
		if(!pas_world(open(av[1], O_RDONLY), save))
			return(printf("error") * 0);
	}
	else
		printf("not .rt file");
	return (0);
}