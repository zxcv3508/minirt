/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyopark <hyopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:58:07 by hyopark           #+#    #+#             */
/*   Updated: 2021/04/08 16:09:39 by hyopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../mlx/mlx.h"

#define SP 1
#define PL 2
#define TR 3
#define SQ 4
#define SY 5

t_vec	vec_mul(t_vec v, double r);
double vec_len(t_vec vec)
{
	return (sqrt(vec.p.x * vec.p.x + vec.p.y * vec.p.y + vec.p.z * vec.p.z));
}






t_point	make_dot(double x, double y, double z)
{
	t_point re;

	re.x = x;
	re.y = y;
	re.z = z;
	return (re);
}
t_ray	make_ray(t_point o, t_vec dir)
{
	t_ray re;

	re.ori = o;
	re.dir = dir;
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

double	vec_cos(t_vec v1, t_vec v2)
{
	return (vec_dot(v1, v2) / (vec_len(v1) * vec_len(v2)));
}

double	vec_sin(t_vec v1, t_vec v2)
{
	return (vec_len(vec_cro(v1, v2)) / (vec_len(v1) * vec_len(v2)));
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	return (make_vec(v1.p.x - v2.p.x, v1.p.y - v2.p.y, v1.p.z - v2.p.z));
}

t_vec	make_vec_dot(t_point d)
{
	t_vec re;

	re.p = d;
	return (re);
}

int     make_rgb(t_col col)
{
         int rgb;

         rgb = (int)col.b + ((int)col.g << 8) + ((int)col.r << 16);
         return (rgb);
}

t_col	rgb_to_col(int	rgb)
{
	t_col re;

	re.r = (rgb & (255 << 16)) >> 16;
	re.g = (rgb & (255 << 8)) >> 8;
	re.b = rgb & 255;
	return (re);
}

t_col	col_mul(t_col c, double r)
{
	if (r > 1.0)
		r = 1.0;
	c.r *= r;
	c.g *= r;
	c.b *= r;
	return (c);
}

double	col_plu(t_col c1, t_col c2)
{
	c1.r += c2.r;
	if(c1.r > 255)
		c1.r = 255;
	c1.g += c2.g;
	if(c1.g > 255)
		c1.g = 255;
	c1.b += c2.b;
	if(c1.b > 255)
		c1.b = 255;
	return (make_rgb(c1));
}


int	color(double r, double g, double b)
{
	t_col	col;

	col.r = r * 255.99;
	col.g = g * 255.99;
	col.b = b * 255.99;
	return (make_rgb(col));
}


double	hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec)
{
	t_vec oc ;

	double tmp;
	oc.p = dot_plu(r.ori, dot_mul(make_dot(-1.0,-1.0,-1.0), o.o));
	double a = vec_dot(r.dir, r.dir);
	double hb =  vec_dot(oc, r.dir);
	double c = vec_dot(oc, oc) - o.r*o.r;
	double d = hb*hb - a*c;

	if (d >= 0)
	{
		double root = sqrt(d);
		if (d == 0)
			tmp = (-1 * hb - root ) / a;
		tmp = (-1 * hb - root) / a;
		if (tmp < rec->t_max && tmp > t_min)
		{
			printf("st : %f ", tmp);
			rec->t = tmp;
			rec->col = make_rgb(o.c);
			rec->t_max = tmp;
			rec->p = make_dot(r.ori.x + tmp * r.dir.p.x, r.ori.y + tmp * r.dir.p.y, r.ori.z + tmp * r.dir.p.z);
			rec->n = make_vec_dot(dot_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = unit_vec(make_vec_dot(dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r))));
			return (make_rgb(o.c));
		}
		return (0);
	}
		return (0);
}

double	hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec)
{

	double	d;
	double	t;
	t_vec	to_hit;
	
	d = vec_dot(o.nv, unit_vec(r.dir));
	if (fabs(d) < 0.000001)
		return (0);
	to_hit = vec_sub(make_vec_dot(o.o), make_vec_dot(r.ori));
	t = vec_dot(to_hit, o.nv) / d;
	if (t < t_min || t > rec-> t_max)
		return (0);
		rec->t = t;
		rec->col = make_rgb(o.c);
		rec->t_max = t;
		rec->p = make_dot(r.ori.x + t * r.dir.p.x, r.ori.y + t * r.dir.p.y, r.ori.z + t * r.dir.p.z);
		rec->p = vec_plu(make_vec_dot(r.ori),vec_mul(r.dir,t)).p;
	//	rec->n = make_vec_dot(dot_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
		rec->n = o.nv;
		return (1);
}
	/*t_vec oc ;

	oc.p = dot_plu(r.ori, dot_mul(make_dot(-1.0,-1.0,-1.0), o.o));
	double a = vec_dot(r.dir, r.dir);
	double hb =  vec_dot(oc, r.dir);

	if (d <0.0)
	{
		double root = sqrt(d);
		double tmp = (-1 * hb - root) / a;
		//if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.ori.x + tmp * r.dir.p.x, r.ori.y + tmp * r.dir.p.y, r.ori.z + tmp * r.dir.p.z);
			rec->n = make_vec_dot(dot_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			//rec->n = make_vec_dot(dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
		//tmp = (-1 * hb + root) / a;
		return (1);
	}
		return (0);

}

double	hit_tr(t_tr o, t_ray r, double t_min, double t_max, t_rec *rec)
{
	t_vec oc ;

	oc.p = dot_plu(r.ori, dot_mul(make_dot(-1.0,-1.0,-1.0), o.o));
	double a = vec_dot(r.dir, r.dir);
	double hb =  vec_dot(oc, r.dir);
	double c = vec_dot(oc, oc) - o.r*o.r;
	double d = hb*hb - a*c;

	if (d > 0)
	{
		double root = sqrt(d);
		double tmp = (-1 * hb - root) / a;
		if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.ori.x + tmp * r.dir.p.x, r.ori.y + tmp * r.dir.p.y, r.ori.z + tmp * r.dir.p.z);
			rec->n = make_vec_dot(dot_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = make_vec_dot(dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
		tmp = (-1 * hb + root) / a;
		if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.ori.x + tmp * r.dir.p.x, r.ori.y + tmp * r.dir.p.y, r.ori.z + tmp * r.dir.p.z);
			rec->n = make_vec_dot(dot_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = make_vec_dot(dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
	}
		return (0);
}

double	hit_sq(t_sq o, t_ray r, double t_min, double t_max, t_rec *rec)
{
	double d = (vec_dot(make_vec_dot(o.o), o.nv)) - vec_dot(make_vec_dot(r.ori), make_vec_dot(o.o)) - vec_dot(r.dir, make_vec_dot(o.o)) ;
	double x1 = (o.o.x +);
	double y1 = (o.o.y + (o.nv.p.y * (0.5 * o.r)));
	double z1 = (o.o.x + (o.nv.p.z * (0.5 * o.r)));
	double y1 =;
	double z1;
	double x2;
	double y2;
	double z2;
	if (d > 0 && )
		return (o.c);
	return (0);
}

double	hit_sy(t_sy o, t_ray r, double t_min, double t_max, t_rec *rec)
{
	t_vec oc ;

	oc.p = dot_plu(r.ori, dot_mul(make_dot(-1.0,-1.0,-1.0), o.o));
	double a = vec_dot(r.dir, r.dir);
	double hb =  vec_dot(oc, r.dir);
	double c = vec_dot(oc, oc) - o.r*o.r;
	double d = hb*hb - a*c;

	if (d > 0)
	{
		double root = sqrt(d);
		double tmp = (-1 * hb - root) / a;
		if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.ori.x + tmp * r.dir.p.x, r.ori.y + tmp * r.dir.p.y, r.ori.z + tmp * r.dir.p.z);
			rec->n = make_vec_dot(dot_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = make_vec_dot(dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
		tmp = (-1 * hb + root) / a;
		if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.ori.x + tmp * r.dir.p.x, r.ori.y + tmp * r.dir.p.y, r.ori.z + tmp * r.dir.p.z);
			rec->n = make_vec_dot(dot_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = make_vec_dot(dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
	}
		return (0);
}
*/



int	hit_type(t_lst *lst, t_ray r, t_rec *rec)
{
 	if (lst->type == SP)
		return (hit_sph(*((t_sp *)lst->obj),r,0,rec));
	if (lst->type == PL)
		return (hit_pl(*((t_pl *)(lst->obj)),r,0,rec));
/* 	if (lst->type == TR)
		return (hit_tr(*((t_pl *)(lst->obj)),r,0,0xffffff,rec));i */
// 	if (lst->type == SQ)
//		return (hit_sq(*((t_sq *)(lst->obj)),r,0,0xffffff,rec));/*
// 	if (lst->type == SY)
//		return (hit_sy(*((t_pl *)(lst->obj)),r,0,0xffffff,rec));
return (0);
}

t_vec	vec_ref(t_vec n, t_vec l)
{
	t_vec re;
	t_vec tmp;
	double	dot_p;

	n = unit_vec(n);
	l = unit_vec(l);
	l = make_vec(l.p.x * -1, l.p.y * -1, l.p.z * -1 );
	dot_p = vec_dot(l, n);
	tmp = make_vec(dot_p * 2.0 * n.p.x, dot_p * 2.0 * n.p.y, dot_p * 2.0 * n.p.z);
	re = vec_sub(l, tmp);
	return (unit_vec(re));
}

double	make_diffuse(t_world *world, t_ray r, t_rec *rec, t_l *light)
{
	t_lst *o = world->o;
	t_ray	r_l;

	r_l.ori = rec->p;
	r_l.dir = unit_vec(vec_sub(make_vec_dot(light->o), make_vec_dot(rec->p)));
	return (light->r * fmax(vec_dot(rec->n, r_l.dir),0.0));
}

t_vec	vec_mul(t_vec v, double r)
{
	t_vec re;

	re.p.x = v.p.x * r;
	re.p.y = v.p.y * r;
	re.p.z = v.p.z * r;
	return(re);
}

double	make_spec(t_world *world, t_ray r, t_rec *rec, t_l *light)
{
//	t_l *light =(t_l *)(world->l->obj);
	t_ray	r_l;

	r_l.ori = rec->p;
	r_l.dir = vec_sub(make_vec_dot(light->o), make_vec_dot(rec->p));//
	return (light->r * fmax(pow(vec_dot(vec_ref(rec->n, r_l.dir), r.dir),10), 0.0));// famx , r.dir * -1!!!
}

int	is_shadow(t_world *world,t_lst *o, t_lst *l, t_rec *rec)
{
	t_rec	rec_l;
	t_ray	l_r;
	int	is_hit;
	t_l *light =(t_l *)(world->l->obj);

	is_hit = 0;
		while (l != NULL)
		{
			l_r.ori = rec->p;
			l_r.dir = vec_sub(make_vec_dot(light->o), make_vec_dot(rec->p));
			
			if ((hit_type(o, l_r, &rec_l) > 0.0))
				is_hit++;
			l = l->next;
		}
	return (is_hit);
}

t_phong	trace_light(t_world *world, t_ray r, t_rec *rec)
{
	t_phong	re;
	t_lst	*l_l = (world->l);
	t_l *light =(t_l *)(world->l->obj);
	t_lst *o = world->o;
	t_ray	r_l;
	int	i;
	int in_shadow;
			t_rec rec_l;
		rec_l.t_max = 99999;

	i = 0;
	while (l_l != NULL)
	{
		in_shadow = 0;//지울지말지 생각해봐야함 ㅇ줄수줄이기도필요하니까 위에거랑같이고민:
		light = (t_l *)(l_l->obj);
		r_l.ori = rec->p;
		r_l.dir = vec_sub(make_vec_dot(light->o), make_vec_dot(rec->p));
		o = world->o;
		while (o != NULL)
		{
			if (hit_type(o, r_l, &rec_l))
				in_shadow = 1;
			o = o->next;
		}
		i++;
		if (!in_shadow)
		{
			re.s += make_spec(world, r, rec, light);
			re.d += make_diffuse(world, r, rec, light);
		}
		l_l = l_l->next;
	}
	re.s /= i;
	re.d /= i;
	if (re.d >1.0)
		re.d = 1;
	if (re.s >1.0)
		re.s = 1;
	return (re);
}

double	trace_light_past(t_world *world, t_ray r, t_rec *rec)
{
	t_l *light =(t_l *)(world->l->obj);
	t_lst *o = world->o;
	t_ray	r_l;
	t_ray	r_l_2;
	int	plus_light;
	t_ray	camera;

	plus_light = 0;
	r_l.ori = rec->p;
//	r_l.dir.p = light->o;//vec_sub@@@@@@@@@@@@@@@@ hoxy r.dir also?
	r_l_2.dir.p = light->o;//vec_sub@@@@@@@@@@@@@@@@ hoxy r.dir also?
	r_l.dir = unit_vec(vec_sub(make_vec_dot(r_l.ori), make_vec_dot(light->o)));
	t_vec tmp;
	tmp.p = make_dot(0.0, 0.0, 0.0);// camera ori
//	r.dir = unit_vec(vec_sub(tmp, make_vec_dot(rec->p)));
	camera.dir = vec_sub(make_vec_dot(rec->p), tmp);
	while (o != NULL)
	{
		t_rec rec_l;
		if (hit_type(o, r_l_2, &rec_l) > 0)
			plus_light++;
		o = o->next;
	}
//	printf("%d", plus_light);
	if (plus_light == 0)
		return (light->r * vec_dot(vec_ref(rec->n, r_l.dir), camera.dir));
	else	
		return (-1);
}

int	check_other_object(t_lst *obj_l, t_ray r,t_rec *rec_tmp, double *closest)
{
	int t;
//	t_lst *obj_l;
	while (obj_l != NULL)
	{
		t =  hit_type(obj_l, r, rec_tmp);
		if(t > 0)
		{
			*closest = rec_tmp->t;
			return (t);
		}
		
		else if (obj_l->next)
		{
			obj_l = obj_l->next;
			continue ;
		}
		return (0);
	}
	return (0);
}

int ray_col(t_world **world, t_ray r)
{
	t_lst *obj_l;
	t_lst *lig_l;
	t_rec  rec;
	t_phong	p;
	double l;
	double d;
	double a;

	rec.t_max = 999999999.0;
	rec.col = 0;
	a = (*world)->a.r;
	obj_l = (*world)->o;
	lig_l = (*world)->l;
	int t;
	while (obj_l != NULL)
	{	
		hit_type(obj_l, r, &rec);
		obj_l = obj_l->next;
	}
		t = rec.col;
	if (t > 0 )
	{
		rec.t_max = 999999999.0;
		p = trace_light(*world, r, &rec);
			printf("l :%f d : %f a : %f\n",p.s, p.d ,a);
		return (col_plu(col_mul(rgb_to_col(t), a + p.d), col_mul(((t_l *)(lig_l->obj))->c, p.s)));
	}
	return (0);
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
	if (s[0] != '-')
		re = (double)inter + re / pow(10, (i - tmp));
	else
	{
		re = (double)inter - re/ pow(10,(i-tmp));
		return (1.0 * re);
	}
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

int	range_check(int col, double min, double max)
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
		//c->nv.p.y *= -1.0;//
		//c->o.y *= -1.0;//
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
	{
		printf("%f,%f\n", (*world)->r.x, (*world)->r.y);
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
		world_lst_add(&((*world)->o), lst_cre((void *)sp), 1);
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

t_world	*init_world()
{
	t_world	*re;

	re = (t_world *)malloc(sizeof(t_world));
	re->o = NULL;
	re->c = NULL;
	re->l = NULL;
	return (re);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void	set_img(t_data *img, t_vars *vars, t_world **world)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (*world)->r.x, (*world)->r.y, "Hello world!");
	img->img = mlx_new_image(vars->mlx, (*world)->r.x, (*world)->r.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	image_rend(t_info *info)
{
	int i;
	int j;
	double u;
	double v;
	t_vec v_tmp;
	t_ray r_tmp;

	j = info->world->r.y -1;
	while (j >= 0)
	{
		i = 0;
		while(i < info->world->r.x)
		{
			u = (double)i / (double)(info->world->r.x-1.0);
			v = (double)j / (double)(info->world->r.y-1.0);
			v_tmp = make_vec(info->llc.p.x + u * info->hor.p.x + v * info->ver.p.x - info->ori.x, info->llc.p.y + u * info->hor.p.y + v * info->ver.p.y - info->ori.y, info->llc.p.z + u * info->hor.p.z + v * info->ver.p.z - info->ori.z);
			t_ray r_tmp = make_ray(info->ori, v_tmp);
			//printf("%d, %d :",i,j);
			info->rgb = ray_col(&(info->world), r_tmp);
			my_mlx_pixel_put(&(info->img),i,j,info->rgb);
			i++;
		}
		j--;
		}
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, info->img.img, 0, 0);
}

double make_degrees(double radians) {
    return radians * (M_PI/ 180.0);
}

t_vec check_vup(t_vec v, t_vec nv)
{
	//if(vec_dot(v,nv) == 0.0)
//	{
//		return (make_vec(1,0,0));
//	}
	return (v);
}

void		cam_set(t_info *info, t_cam *c)
{
	double theta;

	theta = make_degrees(c->r);
	info->v_h = 2.0 * tan(theta / 2.0);
	info->v_w = info->world->r.x/info->world->r.y * info->v_h;
	info->f_l = c->o.z;
	info->ori = c->o;
	info->w = unit_vec(vec_sub(make_vec_dot(info->ori), c->nv));
	info->u = unit_vec(vec_cro(check_vup(make_vec(0.0, -1.0, 0.0), c->nv), info->w));
	info->v = unit_vec(vec_cro(info->w,info->u));
//	info->hor = make_vec(info->v_w * info->u.p.x, 0.0, 0.0);
//	info->ver = make_vec(0.0, info->v_h * info->v.p.y, 0.0);
//	info->llc = make_vec((info->ori.x - info->hor.p.x/2.0 - info->ver.p.x/2.0 - info->w.p.x), (info->ori.y - info->hor.p.y/2.0 - info->ver.p.y/2.0 - info->w.p.y), (info->ori.z - info->hor.p.z/2.0 - info->ver.p.z/2.0 - info->w.p.z));
		printf("%f", c->nv.p.y);
	info->hor = vec_mul(info->u, info->v_w);
	printf(" xyz:%f,%f,%f ,%f\n ",info->hor.p.x,info->hor.p.y,info->hor.p.z, info->v_w);
	info->ver = vec_mul(info->v, info->v_h);
	info->llc = vec_sub(vec_sub(vec_sub(make_vec_dot(info->ori), vec_mul(info->hor, 0.5)), vec_mul(info->ver, 0.5)), info->w);
	printf(" xyz:%f,%f,%f ,%f\n ",info->llc.p.x,info->llc.p.y,info->llc.p.z, info->v_w);
//	info->llc = make_vec((info->ori.x - info->hor.p.x/2.0 - info->ver.p.x/2.0 - info->w.p.x), (info->ori.y - info->hor.p.y/2.0 - info->ver.p.y/2.0 - info->w.p.y), (info->ori.z - info->hor.p.z/2.0 - info->ver.p.z/2.0 - info->w.p.z));
	
}

int		key_press(int keycode, t_info *info)
{
	t_lst	*c_l;
	t_lst	*head;

	c_l = info->world->c;
	head = info->world->c;
	if (keycode == KEY_D)
	{
		if (c_l->next != NULL)
		{
		printf("1\n");
			c_l = c_l->next;
			info->world->c = info->world->c->next;
			cam_set(info, ((t_cam *)(c_l->obj)));
			image_rend(info);
		}
		else
		{
		printf("2\n");
			c_l = c_l->next;
			c_l = info->camera_head;;
			info->world->c = info->camera_head;
			cam_set(info, ((t_cam *)(c_l->obj)));
			image_rend(info);
		}
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}


void	make_world(t_world **world, int is_save)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	info->world = *world;
	info->camera_head = (*world)->c;
	set_img (&(info->img), &(info->vars), world);
	cam_set(info, ((t_cam *)((*world)->c->obj)));
	image_rend(info);
	mlx_hook(info->vars.win, 2,  0, &key_press, info);
    	mlx_loop(info->vars.mlx);
	free(info);
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
	make_world(&world, is_save);
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
