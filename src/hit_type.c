#include "minirt.h"
t_point	ray_at(t_ray *ray, double t)
{
	t_point at;

	at = vec_plu(ray->origin, vec_mul(ray->dir, t));
	return (at);
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

	if (d < 0.0000001)
		return (0);
	else
	{
		sqrted = sqrt(d);
		root = (-hb - sqrted) / a;
		if (root < t_min || rec->t_max < root)
		{
			root = (-hb + sqrted) / a;
			if (root < t_min || rec->t_max < root)
				return (0);
		}
	}
	// rec->t = root;
	// rec->p = ray_at(&r, root);
	// rec->normal = vec_unit(vec_mul(vec_sub(rec->p, o.origin), 1.0 / o.r)); 
	rec->albedo = o.c;
	rec->t_max = root;
	return (1);
}

int	hit_pl(t_pl o, t_ray r, double t_min, t_rec *rec)
{

	double	d;
	double	t;
	t_vec	to_hit;
	
	d = vec_dot(o.nv, r.dir);
	if (fabs(d) < 0.000001)
		return (0);
	to_hit = vec_sub((o.origin), (r.origin));
	t = vec_dot(to_hit, o.nv) / d;
	if (t < t_min || t > rec-> t_max)
	{
		rec->t = t;
		rec->albedo = o.c;
		rec->t_max = t;
		rec->p = vec_make(r.origin.x + t * r.dir.x, r.origin.y + t * r.dir.y, r.origin.z + t * r.dir.z);
		rec->p = vec_plu((r.origin),vec_mul(r.dir,t));
	//	rec->n = (vec_plu(rec->p, dot_mul(make_dot(-1,-1,-1), o.o)));
		rec->normal = o.nv;
		return (1);
	}
		return (2);
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