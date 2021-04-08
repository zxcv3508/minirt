#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# ifndef KEY_D
#  define KEY_D 2
# endif

# ifndef KEY_A
#  define KEY_A 0
# endif

# ifndef KEY_ESC
#  define KEY_ESC 53
# endif

# ifndef SP
#  define SP 1
# endif

# ifndef PL
#  define PL 2
# endif

# ifndef TR
#  define TR 3
# endif

# ifndef SQ
#  define SQ 4
# endif

# ifndef SY
#  define SY 5
# endif

typedef struct									s_vec
{
	double										x;
	double										y;
	double										z;
}												t_vec;

typedef t_vec									t_point;
typedef t_vec									t_color;

typedef struct									s_vars
{
	void										*mlx;
	void										*win;
}												t_vars;

typedef struct									s_ray
{
	t_point										ori;
	t_vec										dir;
}												t_ray;

typedef struct									s_rec
{
	t_point										p;
	t_vec										normal;
	double										t;
	double										t_max;
	double										t_min;
	t_color										albedo;
}												t_rec;

typedef struct									s_data
{
	void										*img;
	char										*addr;
	int											bits_per_pixel;
	int											line_length;
	int											endian;
}												t_data;

typedef struct									s_phong
{
	double										specular;
	double										diffuse;
}												t_phong;

typedef struct									s_l
{
	t_point										origin;
	double										r;
	t_color										c;
}												t_l;

typedef struct									s_tr
{
	t_point										f;
	t_point										s;
	t_point										t;
	t_vec										nv;
	t_color										c;
}												t_tr;

typedef struct									s_pl
{
	t_point										origin;
	t_vec										nv;
	t_color										c;
}												t_pl;

typedef struct									s_sq
{
	t_point										origin;
	t_vec										nv;
	double										r;
	t_color										c;
}												t_sq;

typedef struct									s_cy
{
	t_point										origin;
	t_vec										nv;
	double										d;
	double										h;
	t_color										c;
}												t_cy;

typedef struct									s_sp
{
	t_point										origin;
	double										r;
	t_color										c;
}												t_sp;

typedef struct									s_amb
{
	double										r;
	t_color										c;
}												t_amb;

typedef struct									s_cam
{
	t_point										origin;
	t_vec										nv;
	double										r;
}												t_cam;

typedef struct									s_lst
{
	void										*obj;
	int											type;
	struct s_lst								*next;
}												t_lst;

typedef struct									s_world
{
	t_amb										a;
	t_lst										*object;
	t_lst										*light;
	t_lst										*cam;
}												t_world;

typedef struct									s_info
{
	t_world										*world;
	t_lst										*camera_head;
	t_data										img;
	t_vars										vars;
	double										fov;
	double										viewport_height;
	double										viewport_width;
	double										focal_len;
	t_vec										w;
	t_vec										u;
	t_vec										v;
	t_point										ori;
	t_vec										llc;
	t_vec										hor;
	t_vec										ver;
	int											rgb;
}												t_info;

/*
** Src is : ../src/hit.c
*/
int												hit_type(t_lst *lst, t_ray r, t_rec *rec);

/*
** Src is : ../src/hit_type.c
*/
double											hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec);
double											hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec);
double											hit_tr(t_tr o, t_ray r, double t_min, double t_max, t_rec *rec);
double											hit_sq(t_sq o, t_ray r, double t_min, double t_max, t_rec *rec);
double											hit_cy(t_cy o, t_ray r, double t_min, double t_max, t_rec *rec);

/*
** Src is : ../src/lighting.c
*/
t_vec											vec_ref(t_vec n, t_vec l);
double											make_diffuse(t_world *world, t_ray r, t_rec *rec, t_l *light);
double											make_spec(t_world *world, t_ray r, t_rec *rec, t_l *light);
int												is_shadow(t_world *world,t_lst *o, t_lst *l, t_rec *rec);
t_phong											trace_light(t_world *world, t_ray r, t_rec *rec);

/*
** Src is : ../src/minirt.c
*/
int												make_rgb(t_col col);
t_col											rgb_to_col(int	rgb);
t_col											col_mul(t_col c, double r);
double											col_plu(t_col c1, t_col c2);
int												color(double r, double g, double b);
int												range_check(t_vec v, double min, double max);

/*
** Src is : ../src/parsing.c
*/
