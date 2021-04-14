#include "minirt.h"

static t_bmph	bmp_get_header(t_world *world)
{
	int		width;
	int		height;
	t_bmph	bmph;

	width = world->resolution.x;
	height = world->resolution.y;
	bmph.file_h.magic1 = 'B';
	bmph.file_h.magic2 = 'M';
	bmph.file_h.size = 54 + 4 * width * height;
	bmph.file_h.reserved1 = 0;
	bmph.file_h.reserved2 = 0;
	bmph.file_h.offset = 54;
	bmph.info_h.size = 40;
	bmph.info_h.width = width;
	bmph.info_h.height = -height;
	bmph.info_h.plane = 1;
	bmph.info_h.bit_per_pixel = 32;
	bmph.info_h.compression = 0;
	bmph.info_h.size_image = 4 * width * height;
	bmph.info_h.resolution_x = width;
	bmph.info_h.resolution_y = height;
	bmph.info_h.color_used = 0xffffff;
	bmph.info_h.color_important = 0;
	return (bmph);
}

void			bmp_save(t_world *world)
{
	t_bmph	bmph;
	char	*file_name;
	t_data	*image;
	int		fd;
	int		i;

	file_name = "minirt.bmp";
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	bmph = bmp_get_header(world);
	write(fd, &bmph, 54);
	image = world->mlx_pointer->image;
	i = 0;
	while (i < (image->line_length / 4) * world->resolution.y)
	{
		if (i % (image->line_length / 4) < world->resolution.x)
			write(fd, &image->addr[i * 4], 4);
		++i;
	}
	printf("[%s] : file has been saved\n", file_name);
	close(fd);
	exit(0);
}
