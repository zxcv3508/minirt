/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:15:04 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/07 20:48:53 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINIRT_H
# define MINIRT_H

# define KEY_D 2
# define KEY_A 0
# define KEY_ESC 53
# define SP 1
# define PL 2
# define TR 3
# define SQ 4
# define SY 5

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

int check_word(char **word, int n);

typedef struct	s_dot
{
	double x;
	double y;
	double z;
}		t_dot;

typedef struct	s_vec
{
	t_dot	p;
}		t_vec;

typedef struct  s_vars {
        void    *mlx;
        void    *win;
} t_vars;

typedef struct	s_ray {
	t_dot	ori;
	t_vec	dir;
	double	t;
}		t_ray;

typedef struct	s_rec{
	t_dot	p;
	t_vec	n;
	double	t;
	double	t_max;
	double	t_min;
	int	ff;
	int	col;
}		t_rec;

typedef struct	s_data {
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
	int r;
	int g;
	int b;
}		t_col;


typedef struct	s_l
{
	t_dot o;
	double r;
	t_col c;
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
	t_dot o;
	t_vec nv;
	t_col c;
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
	t_col c;
}		t_cy;

typedef struct	s_sp
{
	t_dot o;
	double r;
	t_col c;
}		t_sp;

typedef struct	s_dot2
{
	double x;
	double y;
}		t_dot2;

typedef struct	s_amb
{
	double r;
	t_col c;
}		t_amb;

typedef struct	s_cam
{
	t_dot	o;
	t_vec	nv;
	double 	r;
}		t_cam;

typedef struct	s_lst
{
	void	*obj;
	int	type;
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
	t_world *world;
	t_lst	*camera_head;
	t_data img;
	t_vars vars;
	double fov;
	double v_h;
	double v_w;
	double f_l;
	t_vec w;
	t_vec u;
	t_vec v;
	t_dot ori;
	t_vec llc;
	t_vec hor;
	t_vec ver;
	int rgb;
}		t_info;

double	ft_atod(char *s);
t_lst	*lst_cre(void *obj);
t_lst	*lstlast(t_lst *lst);
void	world_lst_add(t_lst **lst, t_lst *new, int type);
void	lst_free(t_lst **lst);
void	free_split(char **s);
t_dot	save_dot(char **splited);
int	range_check(int col, double min, double max);
t_col	save_col(char **splited);
int pasing_tr(char **word, t_world **world);
int pasing_sq(char **word, t_world **world);
int pasing_pl(char **word, t_world **world);
int pasing_cy(char **word, t_world **world);
int pasing_l(char **word, t_world **world);
int pasing_c(char **word, t_world **world);
int pasing_a(char **word, t_world **world);
int pasing_r(char **word, t_world **world);
int pasing_sp(char **word, t_world **world);
int	pasing_format_check(char *line, t_world **world);
t_world	*init_world();
void free_world (t_world *world);
void	make_world(t_world ** world, int is_save);
int	pas_world(int fd, int is_save);
int main(int ac, char **av);
#endif
