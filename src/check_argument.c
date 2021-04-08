#include "minirt.h"

void		check_argument(int argc, char *argv[])
{
	int		len;

	if (argc != 2 && argc != 3)
	{
		printf("number of argument shoud be 2 or 3\n");
		exit (1);
	}
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
			exit(1);
	}
	else
	{
		len = ft_strlen(argv[1]);
		if (ft_strncmp(argv[1] + len - 4, ".rt", 4))
			exit(1);
	}
	
}

