/*
** MY_STRUCT_H : 헤더에 추가할 구조체 작성.
** -Start- 줄과 -End- 줄 사이에 사용할 구조체 들을 작성해주세요!
** 여러 구조체를 사용한다면 줄바꿈 후 계속 작성하면 됩니다!
*/

/* -Start-Write your structs just right down */

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}		t_vec;

typedef t_vec	t_dot;
typedef t_vec	t_color;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_ray
{
	t_dot	ori;
	t_vec	dir;
}		t_ray;

typedef struct	s_rec
{
	t_dot	p;
	t_vec	normal;
	double	t;
	double	t_max;
	double	t_min;
	int		col;
}		t_rec;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_phong
{
	double	s;
	double	d;
}		t_phong;

typedef struct	s_col
{
	int	r;
	int	g;
	int	b;
}		t_col;


typedef struct	s_l
{
	t_dot	o;
	double	r;
	t_col	c;
}		t_l;

typedef struct	s_tr
{
	t_dot	f;
	t_dot	s;
	t_dot	t;
	t_vec	nv;
	t_col	c;
}		t_tr;

typedef struct	s_pl
{
	t_dot	o;
	t_vec	nv;
	t_col	c;
}		t_pl;

typedef struct	s_sq
{
	t_dot	o;
	t_vec	nv;
	double	r;
	t_col	c;
}		t_sq;

typedef struct	s_cy
{
	t_dot	o;
	t_vec	nv;
	double	d;
	double	h;
	t_col	c;
}		t_cy;

typedef struct	s_sp
{
	t_dot	o;
	double	r;
	t_col	c;
}		t_sp;

typedef struct	s_dot2
{
	double	x;
	double	y;
}		t_dot2;

typedef struct	s_amb
{
	double	r;
	t_col	c;
}		t_amb;

typedef struct	s_cam
{
	t_dot	o;
	t_vec	nv;
	double	r;
}		t_cam;

typedef struct	s_lst
{
	void	*obj;
	int		type;
	struct s_lst	*next;
}		t_lst;

typedef struct	s_world{
	t_dot2	r;
	t_amb	a;
	t_lst	*o;
	t_lst	*l;
	t_lst	*c;
}		t_world;

typedef struct	s_info
{
	t_world	*world;
	t_lst	*camera_head;
	t_data	img;
	t_vars	vars;
	double	fov;
	double	v_h;
	double	v_w;
	double	f_l;
	t_vec	w;
	t_vec	u;
	t_vec	v;
	t_dot	ori;
	t_vec	llc;
	t_vec	hor;
	t_vec	ver;
	int	rgb;
}		t_info;

/* -End- finish!# */
