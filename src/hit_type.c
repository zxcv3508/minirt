#include "minirt.h"
t_point	ray_at(t_ray *ray, double t)
{
	t_point at;

	at = vec_plu(ray->origin, vec_mul(ray->dir, t));
	return (at);
}
void	set_face_normal(t_ray *r, t_rec *rec)
{
	// 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
	rec->front_face = vec_dot(r->dir, rec->normal) < 0;
	// 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
	if (rec->front_face)
		rec->normal = rec->normal;
	else
		rec->normal = vec_mul(rec->normal, -1);
}

void		get_record(t_rec *rec, double root, void *obj, t_ray *r)
{
	//rec->texture = obj->texture;
	rec->t = root;
	rec->p = ray_at(r, root);
}

int	hit_sph(t_sp o, t_ray r, double t_min, t_rec *rec)
{
	t_vec oc ;

	double root;
	double sqrted; 
	double a;
	double hb;
	double c;
	double d;
	
	oc = vec_sub(r.origin, o.origin);
	a = vec_dot(r.dir, r.dir);
	hb = vec_dot(oc, r.dir);
	c = vec_dot(oc, oc) - (o.r * o.r);
	d = hb * hb - a * c;

	// printf("ocx : %f, ocy : %f, ocz : %f, a : %f, hb : %f, c : %f, d : %f\n",oc.x,oc.y,oc.z,a,hb,c,d);
	// printf("rayx : %f, rayy : %f, rayz : %f\n",r.dir.x, r.dir.y,r.dir.z);
	
 
	if (d < 0.000000)
	{
	
	//	printf("d 문제\n");
		return (0);
	}
	sqrted = sqrt(d);
	root = (-hb - sqrted) / a;
	//printf("max : %f , min : %f", t_min, rec->t_max);
	if (root < t_min || rec->t_max < root)
	{
		root = (-hb + sqrted) / a;
		if (root < t_min || rec->t_max < root)
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(&r, root);
	rec->normal = vec_mul(vec_sub(rec->p, o.origin), 1.0 / o.r);
	//printf("nv: %f,%f,%f\n", rec->normal.x,rec->normal.y,rec->normal.z);
	rec->albedo = o.c;
	rec->t_max = root;
	set_face_normal(&r, rec);
	return (1);
}

int	hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec)
{

	double	denom;
	double	t;
	t_vec	to_hit;

	denom = vec_dot(o.nv, r.dir);
	if (fabs(denom) < 1e-6)
		return (FALSE);
	to_hit = vec_sub(o.origin, r.origin);
	t = vec_dot(to_hit, o.nv) / denom;
	if (t < t_min || t > rec->t_max)
		return (FALSE);
	get_record(rec, t, &o, &r);
	rec->normal = o.nv;
	rec->albedo = o.c;
	set_face_normal(&r, rec);
	return (TRUE);
}
	/*t_vec oc ;vec_make= vec_plu(r.origin, dot_mul(make_dot(-1.0,-1.0,-1.0), o.o));
	double a = vec_dot(r.dir, r.di;
	double hb =  vec_dot(oc, r.dir);

	if (d <0.0)
	{
		double root = sqrt(d);
		double t = (-1 * hb - root) / a;
		//if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.origin.x + tmp * r.dir.p.x, r.origin.y + tmp * r.dir.p.y, r.origin.z + tmp * r.dir.p.z);
			rec->n = (vec_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			//rec->n = (dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
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

	oc.p = vec_plu(r.origin, dot_mul(make_dot(-1.0,-1.0,-1.0), o.o));
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
			rec->p = make_dot(r.origin.x + tmp * r.dir.p.x, r.origin.y + tmp * r.dir.p.y, r.origin.z + tmp * r.dir.p.z);
			rec->n = (vec_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = (dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
		tmp = (-1 * hb + root) / a;
		if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.origin.x + tmp * r.dir.p.x, r.origin.y + tmp * r.dir.p.y, r.origin.z + tmp * r.dir.p.z);
			rec->n = (vec_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = (dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
	}
		return (0);
}

double	hit_sq(t_sq o, t_ray r, double t_min, double t_max, t_rec *rec)
{
	double d = (vec_dot((o.o), o.nv)) - vec_dot((r.origin), (o.o)) - vec_dot(r.dir, (o.o)) ;
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

double	hit_cy(t_cy o, t_ray r, double t_min, double t_max, t_rec *rec)
{
	t_vec oc ;

	oc.p = vec_plu(r.origin, dot_mul(make_dot(-1.0,-1.0,-1.0), o.o));
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
			rec->p = make_dot(r.origin.x + tmp * r.dir.p.x, r.origin.y + tmp * r.dir.p.y, r.origin.z + tmp * r.dir.p.z);
			rec->n = (vec_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = (dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
		tmp = (-1 * hb + root) / a;
		if (tmp < t_max && tmp > t_min)
		{
			rec->t = tmp;
			rec->p = make_dot(r.origin.x + tmp * r.dir.p.x, r.origin.y + tmp * r.dir.p.y, r.origin.z + tmp * r.dir.p.z);
			rec->n = (vec_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
			rec->n = (dot_mul(rec->n.p, make_dot(1.0/o.r, 1.0/o.r, 1.0/o.r)));
		return (1);
		}
	}
		return (0);
}
*/