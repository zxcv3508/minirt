#include "./include/minirt.h"
int			main(int argc, char const *argv[])
{
	int		fd;
	t_world	world;
	t_vars	mlx_pointer;

	check_argument(argc, argv);
	init_world(world, argc);
	parse_world(&world, argv);
	set_mlx(&world, &mlx_pointer);//set_img 변경
	render(world);

	return 0;
}

void		set_mlx(t_world *world, t_vars *mlx_pointer)
{
	t_data	*img;

	mlx_pointer->mlx = mlx_init();
	mlx_pointer->win = mlx_new_window(mlx_pointer->mlx, (*world)->r.x, (*world)->r.y, "Hello world!");
	mlx_pointer->image->img = mlx_new_image(mlx_pointer->mlx, (*world)->r.x, (*world)->r.y);
	mlx_pointer->image->addr = mlx_get_data_addr(mlx_pointer->image->img, &mlx_pointer->image->img->bits_per_pixel, mlx_pointer->image->img->line_length, &img->endian);
	world->mlx_pointer = mlx_pointer;
}

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

void		init_world(t_world *world, int argc)
{
	world->object = NULL;
	world->light = NULL;
	world->cam = NULL;
	if (argc == 3)
		world->is_save = 1;
	else
		world->is_save = 0;
}



void		parse_world(t_world *world, char *argv[])
{
	char	*line;
	int		fd;
	int		gnl_return;

	line = NULL;
	while ((gnl_return = get_next_line(fd, &line)) >= 0)
	{
		if(!parse_a_line(line, &world))
			return (0);
		free(line);
		if (gnl_return == 0)
			break ;
	}
	free(line);
}

t_bool		parse_a_line(char *line, t_world *world)
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

// void		render(t_world	*world)
// {
// 	int i;
// 	int j;
// 	t_vec primary_ray;
// 	t_ray r_tmpixel_colorp;
	
// 	while (i < height)
// 	{
// 		while(j < width)
// 		{
// 			primary_ray = make_primary_ray();
// 			pixel_color = ray_get_color(primary_ray, world);
// 			write_pixel_color_on_mlx_image();
// 		}
// 	}
// 	mlx_put_image_to_window();
// }

// t_color		ray_get_color(t_world *world)
// {
// 	t_color		pixel_color;

// 	pixel_color = color(0,0,0);
// 	if (hit())
// 		pixel_color = get_phong_color();
// 	else
// 		pixel_color = get_background_color();
// 	return (pixel_color);
// }

t_color		get_phong_color()
{
	t_color		light_color;
		
	light_color = color(0,0,0);
	while (light)
	{
		light_color += get_phong_light_from(light, rec);
		light = light->next;
	}
	light_color += global_ambient;
	return (vec_min(rec.albedo * light_color, color(1, 1, 1));
}

t_color		get_phong_light_from(light)
{
	
	make_shadowray();
	if (in_shaodw())
		return (color(0,0,0));
	else
	{
		specular = spec();
		diffuse = diffuse();
		return (sum(spec,diffuse));
	}
}