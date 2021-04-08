/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:46:17 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/08 16:13:13 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../mlx/mlx.h"
//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
#include "minirt.h"



double	vec_dot(t_vec v1, t_vec v2);

t_point	make_dot(double x, double y, double z);
t_point   dot_mul(t_point d1, t_point d2);
typedef struct	s_rec{
	t_point	p;
	t_vec	n;
	double	t;
	int	ff;
}		t_rec;

typedef struct	s_sph
{
	t_point	cen;
	double	rad;	
}		t_sph;

typedef union	s_obj{
	t_sph	sph;
}		t_obj;


t_sph	make_sph(t_point cen, double rad)
{
	t_sph re;
	re.cen = cen;
	re.rad = rad;
	return (re);
}

double vec_len(t_vec vec)
{
	return (sqrt(vec.p.x * vec.p.x + vec.p.y * vec.p.y + vec.p.z * vec.p.z));
}


t_vec	make_vec(double x, double y, double z)
{
	t_vec re;

	re.p.x = x;
	re.p.y = y;
	re.p.z = z;
	return (re);
}

t_point	make_dot(double x, double y, double z)
{
	t_point re;

	re.x = x;
	re.y = y;
	re.z = z;
	return (re);
}


t_vec	unit_vec(t_vec v)
{
	t_vec re;
	double dir = vec_len(v);
	re.p.x = v.p.x / dir;
	re.p.y = v.p.y / dir;
	re.p.z = v.p.z / dir;
	return (re);
}

int     make_rgb(t_col col)
{
         int rgb;

         rgb = (int)col.b + ((int)col.g << 8) + ((int)col.r << 16);
         return (rgb);
}


t_point	dot_plu(t_point d1, t_point d2)
{
	t_point re;
	re.x = d1.x + d2.x;
	re.y = d1.y + d2.y;
	re.z = d1.z + d2.z;

	return (re);
}

t_point   dot_mul(t_point d1, t_point d2)
 {
         t_point re;
         re.x = d1.x * d2.x;
         re.y = d1.y * d2.y;
         re.z = d1.z * d2.z;

         return (re);
}

t_vec	make_vec_dot(t_point d)
{
	t_vec re;

	re.p = d;
	return (re);
}

int	color(double r, double g, double b)
{
	t_col	col;

	col.r = r * 255.99;
	col.g = g * 255.99;
	col.b = b * 255.99;
	return (make_rgb(col));
}


void	lst_add(t_list *lst, t_list *n){
	while (lst->next != NULL)	
		lst = lst->next;
	lst->next = n;
	//n->next = NULL;
}

int ray_col(t_ray r)
{
	t_list *lst = lst_cre(make_sph(make_dot(0,0,-1), 0.1));
	lst_add(lst, lst_cre(make_sph(make_dot(0,0.5,-1), 0.2)));
	t_list *next = lst;
	lst_add(lst, lst_cre(make_sph(make_dot(0.3,0.2,-1), 0.3)));
	lst_add(lst, lst_cre(make_sph(make_dot(0.5,0.2,-1), 0.4)));
	lst_add(lst, lst_cre(make_sph(make_dot(0.5,0.5,-1), 0.5)));
	
	// 리스트 반복 -> if로 모양 확인 후 각 hit_모양으로 분기
	while (lst!=NULL)
	{
	t_rec  rec;
	double t = hit_sph(lst->o ,r,0, 0xffffffff, &rec);
	if (t > 0.0)
	{
		t_vec N = rec.n;
		//t_vec N = unit_vec(make_vec(r.ori.x + t*r.dir.p.x, r.ori.y + t*r.dir.p.y, r.ori.z + t*r.dir.p.z + 1));
		return (color(0.5 * (N.p.x + 1.0), 0.5 * (N.p.y + 1.0), 0.5 * (N.p.z + 1.0)));
	}
	else if(lst->next){
		lst = lst->next;
		continue ;
		}
	
	t_vec u_d = unit_vec(r.dir);
	double t2 = 0.5 * (u_d.p.y + 1.0);
	double a = 1.0 - t2;
	lst= lst->next;
	return (0);
	}
	return (0);
}

t_ray	make_ray(t_point o, t_vec dir)
{
	t_ray re;

	re.ori = o;
	re.dir = dir;
	return (re);
}

double	vec_dot(t_vec v1, t_vec v2)
{
	double re;

	re = v1.p.x * v2.p.x
	 + v1.p.y * v2.p.y
	 + v1.p.z * v2.p.z;
	return (re);
}

t_vec	vec_cro(t_vec v1, t_vec v2)
{
	t_vec re;
	re.p.x = v1.p.y * v2.p.z - v2.p.y * v1.p.z;
	re.p.y = v1.p.z * v2.p.x - v2.p.z * v1.p.x;
	re.p.z = v1.p.x * v2.p.y - v2.p.x * v1.p.y;

	return (re);
}

t_vec	vec_plu(t_vec v1, t_vec v2)
{
	t_vec re;
	re.p.x = v1.p.x + v2.p.x;
	re.p.y = v1.p.y + v2.p.y;
	re.p.z = v1.p.z + v2.p.z;
	return (re);
}

t_vec	make_vec(double x, double y, double z)
{
	t_vec re;

	re.p.x = x;
	re.p.y = y;
	re.p.z = z;
	return (re);
}

t_vec	unit_vec(t_vec v)
{
	t_vec re;
	double dir = vec_len(v);
	re.p.x = v.p.x / dir;
	re.p.y = v.p.y / dir;
	re.p.z = v.p.z / dir;
	return (re);
}

int check_word(char **word, int n)
{
	int i;

	i = 0;
	while (word[i])
		i++;
	if (i == n)
		return(1);
	else
		return (0);
}

double	ft_atod(char *s)
{
	double	re;
	int	tmp;
	int	inter;

	int i;
	tmp = 0;
	i = 0;
	re = 0;
	while (s[i] != '.' && s[i])
		 i++;
	tmp = ft_atoi(s);
	if(s[i] == '.')
		i++;
	inter = tmp;
	tmp = i;
	while(s[i])
	{
		re *= 10.0;
		re += (double)(s[i] - '0');
		i++;
	}
	if (inter >= 0)
		re = inter + re / pow(10, (i - tmp));
	else
		re = inter - re/ pow(10,(i-tmp));
	return (re);
}

t_lst	*lst_cre(void *obj)
{
	t_lst	*re;

	re = (t_lst *)malloc(sizeof(t_lst));
	if(!re)
		return (0);
	re->obj = obj;
	re->next = NULL;
	return (re);
}
t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
{
		lst = lst->next;
}
	return (lst);
}

void	world_lst_add(t_lst **lst, t_lst *new, int type)
{
	t_lst *last;

	new->type = type;
	if (!(*lst))
		*lst = new;
	last = lstlast(*lst);
	last->next = new;
	new->next = NULL;
}

void	lst_free(t_lst **lst)
{
	t_lst *nod;
	t_lst *next;

	nod = *lst;
	while (nod)
	{
		next = nod->next;
		free(nod->obj);
		free(nod);
		nod = next;
	}
}

void	free_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

t_point	save_dot(char **splited)
{
	t_point re;

	re.x = ft_atod(splited[0]);
	re.y = ft_atod(splited[1]);
	re.z = ft_atod(splited[2]);
	free_split(splited);
	return (re);
}

int	range_check( col, double min, double max)
{
	if (col >= min && col <= max)
		return (1);
	else
		return (0);
}

t_col	save_col(char **splited)
{
	t_col re;

	re.r = ft_atoi(splited[0]);
	re.g = ft_atoi(splited[1]);
	re.b = ft_atoi(splited[2]);
	free_split(splited);
	return (re);
}

int pasing_tr(char **word, t_world **world)
{
	t_tr *tr;

	if (!check_word(word, 5))
	{
		free_split(word);
		return (printf("In tr, some ") * 0);
	}
	else
	{
		tr = (t_tr *)malloc(sizeof(t_tr));
		tr->f = save_dot(ft_split(word[1], ','));
		tr->s = save_dot(ft_split(word[2], ','));
		tr->t = save_dot(ft_split(word[3], ','));
		tr->c = save_col(ft_split(word[4], ','));
		world_lst_add(&((*world)->o), lst_cre((void *)tr), 3);
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_sq(char **word, t_world **world)
{
	t_sq *sq;

	if (!check_word(word, 5))
	{
		free_split(word);
		return (printf("In sq, some ") * 0);
	}
	else
	{
		sq = (t_sq *)malloc(sizeof(t_sq));
		sq->o = save_dot(ft_split(word[1], ','));
		sq->nv.p = save_dot(ft_split(word[2], ','));
		sq->r = ft_atod(word[3]);
		sq->c = save_col(ft_split(word[4], ','));
		world_lst_add(&((*world)->o), lst_cre((void *)sq), 4);
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_pl(char **word, t_world **world)
{
	t_pl *pl;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In pl, some ") * 0);
	}
	else
	{
		pl = (t_pl *)malloc(sizeof(t_pl));
		pl->o = save_dot(ft_split(word[1], ','));
		pl->nv.p = save_dot(ft_split(word[2], ','));
		pl->c = save_col(ft_split(word[3], ','));
		world_lst_add(&((*world)->o), lst_cre((void *)pl), 2);
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_cy(char **word, t_world **world)
{
	t_cy *cy;

	if (!check_word(word, 6))
	{
		free_split(word);
		return (printf("In cy, some ") * 0);
	}
	else
	{
		cy = (t_cy *)malloc(sizeof(t_cy));
		cy->o = save_dot(ft_split(word[1], ','));
		cy->nv.p = save_dot(ft_split(word[2], ','));
		cy->d = ft_atod(word[3]);
		cy->h = ft_atod(word[4]);
		cy->c = save_col(ft_split(word[5], ','));
		world_lst_add(&((*world)->o), lst_cre((void *)cy), 5);
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_l(char **word, t_world **world)
{
	t_l *l;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In l, some ") * 0);
	}
	else
	{
		l = (t_l *)malloc(sizeof(t_l));
		l->o = save_dot(ft_split(word[1], ','));
		l->r = ft_atod(word[2]);
		l->c = save_col(ft_split(word[3], ','));
		world_lst_add(&((*world)->l), lst_cre((void *)l), 1);
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_c(char **word, t_world **world)
{
	t_cam *c;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In c, some ") * 0);
	}
	else
	{
		c = (t_cam *)malloc(sizeof(t_cam));
		c->o = save_dot(ft_split(word[1], ','));
		c->nv.p = save_dot(ft_split(word[2], ','));
		c->r = ft_atod(word[3]);
		world_lst_add(&((*world)->c), lst_cre((void *)c), 1);
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_a(char **word, t_world **world)
{
	if (!check_word(word, 3))
	{
		free_split(word);
		return (printf("In a, some ") * 0);
	}
	else
	{
		(*world)->a.r = ft_atod(word[1]);
		(*world)->a.c = save_col(ft_split(word[2], ','));
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_r(char **word, t_world **world)
{

	if (!check_word(word, 3))
	{
		free_split(word);
		return (printf("In R, some ") * 0);
	}
	if ((*world)->r.x >= 1 && (*world)->r.y >= 1)
{	printf("%f,%f\n", (*world)->r.x, (*world)->r.y);
		return (printf("R already exist ") * 0);
}
	else
	{
		(*world)->r.x = ft_atod(word[1]);
		(*world)->r.y = ft_atod(word[2]);
		free_split(word);
		return (1);
	}
	return (0);
}

int pasing_sp(char **word, t_world **world)
{
	t_sp *sp;

	if (!check_word(word, 4))
	{
		free_split(word);
		return (printf("In sp, some ") * 0);
	}
	else
	{
		sp = (t_sp *)malloc(sizeof(t_sp));
		sp->o = save_dot(ft_split(word[1], ','));
		sp->r = ft_atod(word[2]);
		sp->c = save_col(ft_split(word[3], ','));
		//if (!(range_check(sp->c.r, 0, 255) && range_check(sp->c.g, 0, 255) && range_check(sp->c.b, 0, 255) ))
		//	return (printf("color ") * 0);
		world_lst_add(&((*world)->o), lst_cre((void *)sp),1);
		free_split(word);
		return (1);
	}
	return (0);
}

int	pasing_format_check(char *line, t_world **world)
{
	char **word;

	if (!*line)
		return (1);
	word = ft_split(line,' ');
	if(!ft_strncmp(*word,"R",1))
		return(pasing_r(word, world));
	else if(!ft_strncmp(*word,"A",1))
		return(pasing_a(word, world));
	else if(!ft_strncmp(*word,"cy",2))
		return(pasing_cy(word, world));
	else if(!ft_strncmp(*word,"c",1))
		return(pasing_c(word, world));
	else if(!ft_strncmp(*word,"l",1))
		return(pasing_l(word, world));
	else if(!ft_strncmp(*word,"sp",2))
		return(pasing_sp(word, world));
	else if(!ft_strncmp(*word,"pl",2))
		return(pasing_pl(word, world));
	else if(!ft_strncmp(*word,"sq",2))
		return(pasing_sq(word, world));
	else if(!ft_strncmp(*word,"tr",2))
		return(pasing_tr(word, world));
	free_split(word);
	return (printf("wrong init ") * 0);
}
int	make_world(t_world **world, int is_save)
{
	double	a_r = 16.0 / 9.0;
	int i_w = 192*5;
	int i_h = (int)(i_w / a_r);
	
	double v_h = 2.0;
	double v_w = a_r * v_h;
	double f_l = 1.0;

	t_point ori = make_dot(0.0, 0.0, 0.0);
	t_vec hor = make_vec(v_w, 0.0, 0.0);
	t_vec ver = make_vec(0.0, v_h, 0.0);
	t_vec llc = make_vec((ori.x - hor.p.x/2.0 - ver.p.x/2.0), (ori.y - hor.p.y/2.0 - ver.p.y/2.0), (ori.z - hor.p.z/2.0 - ver.p.z/2.0 - f_l));// 빼기 연산자 아니 연산자 다만들어야함

	t_data	img;
	t_vars	vars;
	int rgb = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, i_w, i_h, "Hello world!");
	img.img = mlx_new_image(vars.mlx, i_w, i_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for(int j = i_h - 1; j >= 0 ; --j)
	{
		printf("%d",j);
		for(int i = 0; i < i_w  ; ++i)
		{
			double u = (double)i / (double)(i_w-1.0);
			double v = (double)j / (double)(i_h-1.0);
			t_vec v_tmp = make_vec(llc.p.x + u*hor.p.x + v*ver.p.x - ori.x, llc.p.y + u*hor.p.y + v*ver.p.y - ori.y, llc.p.z + u*hor.p.z + v*ver.p.z - ori.z);
			t_ray r_tmp = make_ray(ori, v_tmp);
			rgb = ray_col(r_tmp); 
			my_mlx_pixel_put(&img,i,j,rgb);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);//이미지를 윈도우에 올린다.
	mlx_hook(vars.win, 3, 1L<<0, close, &vars);
    	mlx_loop(vars.mlx);
}

void free_world (t_world *world)
{
	lst_free(&(world->o));
	lst_free(&(world->c));
	lst_free(&(world->l));
	free(world);
}

int	pas_world(int fd, int is_save)
{
	char	*line;
	int	i;
	t_world	*world;

	i = 0;
	if (fd < 3)
		return (printf("opne ") * 0);
	world = init_world();
	while (get_next_line(fd, &line))
	{
		if(!pasing_format_check(line, &world))
			return(0);
		free(line);
	}
	make_world(world, is_save);
	if(is_save)
		{}
	free(line);
	free_world(world);
	return (1);
}


int main(int ac, char **av)
{
	int	save;

	if (ac <= 1 || ac >3)
		return (printf("arg num error") * 0);
	if (ac == 3)
	{
		if(ft_strnstr(av[2], "--save", 6))
			save = 1;
		else
			return (printf("3arg error") * 0);
	}
	if (!ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3))
	{
		if(!pas_world(open(av[1], O_RDONLY), save))
			return(printf("error") * 0);
	}
	else
		printf("not .rt file");
	return (0);
}
