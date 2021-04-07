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

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef t_vec		t_dot;
typedef t_vec		t_color;
typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_ray
{
	t_dot			ori;
	t_vec			dir;
}					t_ray;

typedef struct		s_rec
{
	t_dot			p;
	t_vec			normal;
	double			t;
	double			t_max;
	double			t_min;
	int				col;
}					t_rec;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_phong
{
	double			s;
	double			d;
}					t_phong;

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

typedef struct		s_l
{
	t_dot			o;
	double			r;
	t_col			c;
}					t_l;

typedef struct		s_tr
{
	t_dot			f;
	t_dot			s;
	t_dot			t;
	t_vec			nv;
	t_col			c;
}					t_tr;

typedef struct		s_pl
{
	t_dot			o;
	t_vec			nv;
	t_col			c;
}					t_pl;

typedef struct		s_sq
{
	t_dot			o;
	t_vec			nv;
	double			r;
	t_col			c;
}					t_sq;

typedef struct		s_cy
{
	t_dot			o;
	t_vec			nv;
	double			d;
	double			h;
	t_col			c;
}					t_cy;

typedef struct		s_sp
{
	t_dot			o;
	double			r;
	t_col			c;
}					t_sp;

typedef struct		s_dot2
{
	double			x;
	double			y;
}					t_dot2;

typedef struct		s_amb
{
	double			r;
	t_col			c;
}					t_amb;

typedef struct		s_cam
{
	t_dot			o;
	t_vec			nv;
	double			r;
}					t_cam;

typedef struct		s_lst
{
	void			*obj;
	int				type;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_world{
	t_dot2			r;
	t_amb			a;
	t_lst			*o;
	t_lst			*l;
	t_lst			*c;
}					t_world;

typedef struct		s_info
{
	t_world			*world;
	t_lst			*camera_head;
	t_data			img;
	t_vars			vars;
	double			fov;
	double			v_h;
	double			v_w;
	double			f_l;
	t_vec			w;
	t_vec			u;
	t_vec			v;
	t_dot			ori;
	t_vec			llc;
	t_vec			hor;
	t_vec			ver;
	int				rgb;
}					t_info;

/*
** Src is : ../src/minirt_2.c
*/
int					make_rgb(t_col col);
t_col				rgb_to_col(int	rgb);
t_col				col_mul(t_col c, double r);
double				col_plu(t_col c1, t_col c2);
int					color(double r, double g, double b);
double				hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec);
double				hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec);
double				hit_tr(t_tr o, t_ray r, double t_min, double t_max, t_rec *rec);
double				hit_sq(t_sq o, t_ray r, double t_min, double t_max, t_rec *rec);
double				hit_cy(t_cy o, t_ray r, double t_min, double t_max, t_rec *rec);
int					hit_type(t_lst *lst, t_ray r, t_rec *rec);
t_vec				vec_ref(t_vec n, t_vec l);
double				make_diffuse(t_world *world, t_ray r, t_rec *rec, t_l *light);
double				make_spec(t_world *world, t_ray r, t_rec *rec, t_l *light);
int					is_shadow(t_world *world,t_lst *o, t_lst *l, t_rec *rec);
t_phong				trace_light(t_world *world, t_ray r, t_rec *rec);
int					ray_col(t_world **world, t_ray r);
int					check_word(char **word, int n);
double				ft_atod(char *s);
t_lst				*lst_cre(void *obj);
t_lst				*lstlast(t_lst *lst);
void				world_lst_add(t_lst **lst, t_lst *new, int type);
void				lst_free(t_lst **lst);
void				free_split(char **s);
t_dot				save_dot(char **splited);
int					range_check(int col, double min, double max);
t_col				save_col(char **splited);
int					pasing_tr(char **word, t_world **world);
int					pasing_sq(char **word, t_world **world);
int					pasing_pl(char **word, t_world **world);
int					pasing_cy(char **word, t_world **world);
int					pasing_l(char **word, t_world **world);
int					pasing_c(char **word, t_world **world);
int					pasing_a(char **word, t_world **world);
int					pasing_r(char **word, t_world **world);
int					pasing_sp(char **word, t_world **world);
int					pasing_format_check(char *line, t_world **world);
t_world				*init_world();
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				set_img(t_data *img, t_vars *vars, t_world **world);
void				image_rend(t_info *info);
double				make_degrees(double radians);
t_vec				check_vup(t_vec v, t_vec nv);
void				cam_set(t_info *info, t_cam *c);
int					key_press(int keycode, t_info *info);
void				make_world(t_world **world, int is_save);
void				free_world(t_world *world);
int					pas_world(int fd, int is_save);

/*
** Src is : ../src/vec_utils.c
*/
double				vec_len(t_vec vec);
t_vec				vec_make(double x, double y, double z);
t_ray				make_ray(t_dot o, t_vec dir);
t_vec				vec_unit(t_vec v);
t_vec				vec_plu(t_vec d1, t_vec d2);
t_vec				vec_pow(t_vec d1, t_vec d2);
t_vec				vec_mul(t_vec v, double r);
double				vec_dot(t_vec v1, t_vec v2);
t_vec				vec_cro(t_vec v1, t_vec v2);
t_vec				vec_plu(t_vec v1, t_vec v2);
double				vec_cos(t_vec v1, t_vec v2);
double				vec_sin(t_vec v1, t_vec v2);
t_vec				vec_sub(t_vec v1, t_vec v2);

#endif
