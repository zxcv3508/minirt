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

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

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

typedef int			t_bool;
typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef t_vec		t_point;
typedef t_vec		t_color;
typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	t_data			*image;
}					t_vars;

typedef struct		s_ray
{
	t_point			origin;
	t_vec			dir;
}					t_ray;

typedef struct		s_rec
{
	t_point			p;
	t_vec			normal;
	double			t;
	double			t_max;
	double			t_min;
	t_color			albedo;
}					t_rec;

typedef struct		s_phong
{
	double			specular;
	double			diffuse;
}					t_phong;

typedef struct		s_l
{
	t_point			origin;
	double			r;
	t_color			c;
}					t_l;

typedef struct		s_tr
{
	t_point			f;
	t_point			s;
	t_point			t;
	t_vec			nv;
	t_color			c;
}					t_tr;

typedef struct		s_pl
{
	t_point			origin;
	t_vec			nv;
	t_color			c;
}					t_pl;

typedef struct		s_sq
{
	t_point			origin;
	t_vec			nv;
	double			r;
	t_color			c;
}					t_sq;

typedef struct		s_cy
{
	t_point			origin;
	t_vec			nv;
	double			d;
	double			h;
	t_color			c;
}					t_cy;

typedef struct		s_sp
{
	t_point			origin;
	double			r;
	t_color			c;
}					t_sp;

typedef struct		s_amb
{
	double			r;
	t_color			c;
}					t_amb;

typedef struct		s_cam
{
	t_point			look_from;
	t_vec			look_at;
	double			fov;
	double			view_h;
	double			view_w;
	double			focal_lenght;
	t_vec			w;
	t_vec			u;
	t_vec			v;
	t_vec			lower_left_corner;
	t_vec			horizontal;
	t_vec			vertical;
}					t_cam;

typedef struct		s_lst
{
	void			*obj;
	int				type;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_world
{
	t_vec			resolution;
	t_amb			amb;
	t_lst			*object;
	t_lst			*light;
	t_lst			*cam;
	t_vars			*mlx_pointer;
	int				is_save;
}					t_world;

typedef struct		s_info
{
	t_world			*world;
	t_lst			*camera_head;
	t_data			img;
	t_vars			vars;
	int				rgb;
}					t_info;

/*
** Src is : ../src/check_argument.c
*/
void				check_argument(int argc, char *argv[]);

/*
** Src is : ../src/color_util.c
*/
t_color				make_color(double r, double g, double b);

/*
** Src is : ../src/hit.c
*/
int					hit_type(t_lst *lst, t_ray r, t_rec *rec);

/*
** Src is : ../src/hit_type.c
*/
double				hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec);
double				hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec);
double				hit_tr(t_tr o, t_ray r, double t_min, double t_max, t_rec *rec);
double				hit_sq(t_sq o, t_ray r, double t_min, double t_max, t_rec *rec);
double				hit_cy(t_cy o, t_ray r, double t_min, double t_max, t_rec *rec);

/*
** Src is : ../src/init_world.c
*/
void				init_world(t_world *world, int argc);

/*
** Src is : ../src/lighting.c
*/
t_vec				vec_ref(t_vec n, t_vec l);
double				make_diffuse(t_world *world, t_ray r, t_rec *rec, t_l *light);
double				make_spec(t_world *world, t_ray r, t_rec *rec, t_l *light);
int					is_shadow(t_world *world,t_lst *o, t_lst *l, t_rec *rec);

/*
** Src is : ../src/minirt.c
*/
int					make_rgb(t_color col);
t_color				rgb_to_col(int	rgb);
t_color				col_mul(t_color c, double r);
double				col_plu(t_color c1, t_color c2);
int					color(double r, double g, double b);
int					range_check(t_vec v, double min, double max);

/*
** Src is : ../src/parsing.c
*/
t_bool				parse_a_line(char *line, t_world *world);
void				parse_world(t_world *world, char *argv[]);

/*
** Src is : ../src/parsing_type_1.c
*/
int					pasing_c(char **word, t_world **world);
int					pasing_a(char **word, t_world **world);
int					pasing_r(char **word, t_world **world);
int					pasing_sp(char **word, t_world **world);
int					pasing_l(char **word, t_world **world);

/*
** Src is : ../src/parsing_type_2.c
*/
int					pasing_tr(char **word, t_world **world);
int					pasing_sq(char **word, t_world **world);
int					pasing_pl(char **word, t_world **world);
int					pasing_cy(char **word, t_world **world);

/*
** Src is : ../src/parsing_util_free.c
*/
void				free_split(char **s);
void				lst_free(t_lst **lst);
void				free_world(t_world *world);

/*
** Src is : ../src/parsing_util_save.c
*/
t_color				save_col(char **splited);
t_point				save_dot(char **splited);
void				world_lst_add(t_lst **lst, t_lst *new, int type);

/*
** Src is : ../src/parsing_util_tool.c
*/
double				ft_atod(char *s);
t_lst				*lst_cre(void *obj);
t_lst				*lstlast(t_lst *lst);
int					check_word(char **word, int n);

/*
** Src is : ../src/ray_color.c
*/
t_color				get_phong_color();
t_color				get_phong_light_from();
t_color				ray_get_color(t_world *world);

/*
** Src is : ../src/render.c
*/
void				make_world(t_world **world, int is_save);
t_color				ray_get_color(t_world *world);
void				render(t_world	*world);
int					key_press(int keycode, t_info *info);

/*
** Src is : ../src/render_cam.c
*/
void				cam_set(t_info *info, t_cam *c);

/*
** Src is : ../src/render_util.c
*/
double				make_degrees(double radians);
t_vec				check_vup(t_vec v, t_vec nv);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
** Src is : ../src/set_mlx.c
*/
void				set_mlx(t_world *world, t_vars *mlx_pointer);

/*
** Src is : ../src/vec_util.c
*/
double				vec_size(t_vec vec);
t_vec				vec_make(double x, double y, double z);
t_ray				make_ray(t_point o, t_vec dir);
t_vec				vec_unit(t_vec v);
t_vec				vec_pow(t_vec d1, t_vec d2);
t_vec				vec_mul(t_vec v, double r);
double				vec_dot(t_vec v1, t_vec v2);
t_vec				vec_cro(t_vec v1, t_vec v2);
t_vec				vec_plu(t_vec v1, t_vec v2);
double				vec_cos(t_vec v1, t_vec v2);
double				vec_sin(t_vec v1, t_vec v2);
t_vec				vec_sub(t_vec v1, t_vec v2);

#endif
