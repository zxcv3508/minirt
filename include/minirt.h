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

# ifndef CY
#  define CY 5
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
	double			front_face;
}					t_rec;

typedef struct		s_phong
{
	double			specular;
	double			diffuse;
}					t_phong;

typedef struct		s_light
{
	t_point			origin;
	double			r;
	t_color			c;
	double			len;
}					t_light;

typedef struct		s_tr
{
	t_point			p1;
	t_point			p2;
	t_point			p3;
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
	t_vec			vec;
	t_vec			n;
	double			len;
	double			r;
	t_color			c;
}					t_cy;

typedef struct		s_disc_set
{
	t_vec			to_hit;
	t_vec			p;
	double			denom;
	double			t;
}					t_disc_set;

typedef struct		s_cy_set
{
	t_vec			delp;
	t_vec			nv;
	t_point			p;
	double			sqrtd;
	double			len;
	double			discriminant;
	double			root;
	double			a;
	double			b;
	double			c;
}					t_cy_set;

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

typedef struct		s_world
{
	t_vec			resolution;
	t_amb			amb;
	t_lst			*object;
	t_lst			*light;
	t_lst			*cam;
	t_vars			*mlx_pointer;
	t_lst			*camera_head;
	int				is_save;
}					t_world;

# pragma pack(push, 1)
typedef struct		s_bmph_file
{
	unsigned char	magic1;
	unsigned char	magic2;
	unsigned int	size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	offset;
}					t_bmph_file;

typedef struct		s_bmph_info
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
}					t_bmph_info;

typedef struct		s_bmph
{
	t_bmph_file		file_h;
	t_bmph_info		info_h;
}					t_bmph;

# pragma pack(pop)
/*
** Src is : ../src/bmp_save.c
*/
void				bmp_save(t_world *world);

/*
** Src is : ../src/check_argument.c
*/
int					check_argument(int ac, char **av);

/*
** Src is : ../src/hit.c
*/
int					hit(t_lst *obj_l, t_ray primary_ray, t_rec *rec);
int					hit_type(t_lst *lst, t_ray r, t_rec *rec);

/*
** Src is : ../src/hit_cy.c
*/
int					hit_cy(t_cy obj, t_ray r, double t_min, t_rec *rec);

/*
** Src is : ../src/hit_pl.c
*/
int					hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec);

/*
** Src is : ../src/hit_sp.c
*/
int					hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec);

/*
** Src is : ../src/hit_sq.c
*/
int					hit_sq(t_sq o, t_ray r, double t_min,  t_rec *rec);
int					is_inside_square(t_sq *square, t_point p);

/*
** Src is : ../src/hit_tr.c
*/
double				hit_tr(t_tr o, t_ray r, double t_min, t_rec *rec);
int					is_inside(t_point p1, t_point p2, t_point p3, t_point p);

/*
** Src is : ../src/hit_util.c
*/
t_point				ray_at(t_ray *ray, double t);
void				set_face_normal(t_ray *r, t_rec *rec);
void				get_record(t_rec *rec, double root, void *obj, t_ray *r);
int					is_aligned(t_vec vec);

/*
** Src is : ../src/parsing.c
*/
t_bool				parse_a_line(char *line, t_world **world);
int					parse_world(t_world *world, char *argv[]);

/*
** Src is : ../src/parsing_cam_set.c
*/
t_vec				vup(t_vec v);
double				make_degrees(double radians);
void				cam_set(t_world **world,t_cam *camera);

/*
** Src is : ../src/parsing_init_world.c
*/
void				init_world(t_world *world, int argc);

/*
** Src is : ../src/parsing_type_object.c
*/
int					pasing_sp(char **word, t_world **world);
int					pasing_tr(char **word, t_world **world);
int					pasing_sq(char **word, t_world **world);
int					pasing_pl(char **word, t_world **world);
int					pasing_cy(char **word, t_world **world);

/*
** Src is : ../src/parsing_type_world.c
*/
int					pasing_c(char **word, t_world **world);
int					pasing_a(char **word, t_world **world);
int					pasing_r(char **word, t_world **world);
int					pasing_l(char **word, t_world **world);

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
int					range_check(t_vec v, double min, double max);
double				ft_atod(const char *s);
t_lst				*lst_cre(void *obj);
t_lst				*lstlast(t_lst *lst);
int					check_word(char **word, int n);

/*
** Src is : ../src/ray_get_color.c
*/
t_color				ray_get_color(t_world *world,t_ray primary_ray);
t_color				get_phong_color(t_world *world, t_ray primary_ray, t_rec *rec);
t_color				get_phong_light_from(t_world *world, t_ray primary_ray, t_rec *rec, t_light *light);

/*
** Src is : ../src/ray_make.c
*/
t_ray				make_primary_ray(t_world	*world, t_cam *camera, int i, int j);
t_ray				make_shadow_ray(t_ray primary_ray, t_light *light, t_rec *rec);

/*
** Src is : ../src/ray_phong_lighting.c
*/
t_vec				vec_ref(t_vec n, t_vec l);
t_color				make_diffuse(t_ray primary_ray, t_rec *rec, t_light *light);
t_color				make_spec(t_ray primary_ray, t_rec *rec, t_light *light);

/*
** Src is : ../src/ray_shadow.c
*/
int					in_shadow(t_lst *obj_list, t_ray shadow_ray, t_light *light, t_rec *rec);

/*
** Src is : ../src/render.c
*/
void				render(t_world	*world, t_cam *camera);
int					make_rgb(t_color col);
void				write_pixel_color_on_mlx_image(t_data *data, int x, int y, int color);

/*
** Src is : ../src/render_util.c
*/
t_vec				check_vup(t_vec v, t_vec nv);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					key_press(int keycode, t_world *world);

/*
** Src is : ../src/set_mlx.c
*/
void				set_mlx(t_world *world, t_vars *mlx_pointer);

/*
** Src is : ../src/vec_util.c
*/
double				vec_len_squared(t_vec vec);
double				vec_size(t_vec vec);
t_vec				vec_make(double x, double y, double z);
t_ray				make_ray(t_point o, t_vec dir);
t_vec				vec_unit(t_vec v);
t_vec				vec_pow(t_vec d1, t_vec d2);
t_vec				vec_mul(t_vec v, double r);
double				vec_dot(t_vec v1, t_vec v2);
t_vec				vec_cro(t_vec v1, t_vec v2);
t_vec				vec_plu(t_vec v1, t_vec v2);
t_vec				vec_max(t_vec v1, t_vec v2);
t_vec				vec_min(t_vec v1, t_vec v2);
double				vec_cos(t_vec v1, t_vec v2);
double				vec_sin(t_vec v1, t_vec v2);
t_vec				vec_sub(t_vec v1, t_vec v2);

#endif
