#include "minirt.h"

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