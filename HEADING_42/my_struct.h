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
}				t_rec;

typedef struct	s_phong
{
	double		specular;
	double		diffuse;
}		t_phong;

typedef struct	s_l
{
	t_point	origin;
	double	r;
	t_color	c;
}		t_l;

typedef struct	s_tr
{
	t_point	f;
	t_point	s;
	t_point	t;
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
	t_vec	nv;
	double	d;
	double	h;
	t_color	c;
}		t_cy;

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

typedef struct	s_world
{
	t_vec	resolution;
	t_amb	amb;
	t_lst	*object;
	t_lst	*light;
	t_lst	*cam;
	t_vars	*mlx_pointer;
	int		is_save;
}		t_world;

typedef struct	s_info
{
	t_world	*world;
	t_lst	*camera_head;
	t_data	img;
	t_vars	vars;
	int		rgb;
}		t_info;

/* -End- finish!# */
