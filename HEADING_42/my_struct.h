/*
** MY_STRUCT_H : 헤더에 추가할 구조체 작성.
** -Start- 줄과 -End- 줄 사이에 사용할 구조체 들을 작성해주세요!
** 여러 구조체를 사용한다면 줄바꿈 후 계속 작성하면 됩니다!
*/

/* -Start-Write your structs just right down */
typedef int	t_bool;

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef t_vec	t_point;
typedef t_vec	t_color;

typedef struct	s_ray
{
	t_point		origin;
	t_vec		dir;
}				t_ray;

typedef struct	s_rec
{
	t_point		p;
	t_vec		normal;
	double		t;
	double		t_max;
	double		t_min;
	t_color		albedo;
	double		front_face;
}				t_rec;

typedef struct	s_phong
{
	double		specular;
	double		diffuse;
}		t_phong;

typedef struct	s_light
{
	t_point	origin;
	double	r;
	t_color	c;
	double	len;
}		t_light;

typedef struct	s_tr
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_vec	nv;
	t_color	c;
}		t_tr;

typedef struct	s_pl
{
	t_point	origin;
	t_vec	nv;
	t_color	c;
}		t_pl;

typedef struct	s_sq
{
	t_point	origin;
	t_vec	nv;
	double	r;
	t_color	c;
}		t_sq;

typedef struct	s_cy
{
	t_point	origin;
	t_vec	vec;
	t_vec	n;
	double	len;
	double	r;
	t_color	c;
}		t_cy;

typedef struct	s_disc_set
{
	t_vec	to_hit;
	t_vec	p;
	double	denom;
	double	t;
	
	
}		t_disc_set;

typedef struct	s_cy_set
{
	t_vec	delp;
	t_vec	nv;
	t_point	p;
	double	sqrtd;
	double	len;
	double	discriminant;
	double	root;
	double	a;
	double	b;
	double	c;
}		t_cy_set;

typedef struct	s_sp
{
	t_point	origin;
	double	r;
	t_color	c;
}		t_sp;

typedef struct	s_amb
{
	double	r;
	t_color	c;
}		t_amb;

typedef struct	s_cam
{
	t_point	look_from;
	t_vec	look_at;
	double	fov;
	double	view_h;
	double	view_w;
	double	focal_lenght;
	t_vec	w;
	t_vec	u;
	t_vec	v;
	t_vec	lower_left_corner;
	t_vec	horizontal;
	t_vec	vertical;
}			t_cam;

typedef struct	s_lst
{
	void	*obj;
	int		type;
	struct s_lst	*next;
}		t_lst;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_data		*image;
}				t_vars;

typedef struct	s_world
{
	t_vec	resolution;
	t_amb	amb;
	t_lst	*object;
	t_lst	*light;
	t_lst	*cam;
	t_vars	*mlx_pointer;
	t_lst	*camera_head;
	int		is_save;
}		t_world;

# pragma pack(push, 1)

typedef struct	s_bmph_file
{
	unsigned char	magic1;
	unsigned char	magic2;
	unsigned int	size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	offset;
}		t_bmph_file;

typedef struct	s_bmph_info
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	plane;
	unsigned short	bit_per_pixel;
	unsigned int	compression;
	unsigned int	size_image;
	unsigned int	resolution_x;
	unsigned int	resolution_y;
	unsigned int	color_used;
	unsigned int	color_important;
}		t_bmph_info;

typedef struct	s_bmph
{
	t_bmph_file		file_h;
	t_bmph_info		info_h;
}				t_bmph;

# pragma pack(pop)

/* -End- finish!# */
