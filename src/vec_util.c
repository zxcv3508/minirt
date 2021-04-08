#include "minirt.h"

double	vec_size(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}


t_vec	vec_make(double x, double y, double z)
{
	t_vec re;

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

t_vec	vec_unit(t_vec v)
{
	t_vec re;
	double dir = vec_len(v);
	re.x = v.x / dir;
	re.y = v.y / dir;
	re.z = v.z / dir;
	return (re);
}


t_vec	vec_pow(t_vec d1, t_vec d2)
 {
         t_vec re;
		 
         re.x = d1.x * d2.x;
         re.y = d1.y * d2.y;
         re.z = d1.z * d2.z;

         return (re);
}

t_vec	vec_mul(t_vec v, double r)
{
	t_vec re;

	re.x = v.x * r;
	re.y = v.y * r;
	re.z = v.z * r;
	return(re);
}

double	vec_dot(t_vec v1, t_vec v2)
{
	double re;

	re = v1.x * v2.x
	 + v1.y * v2.y
	 + v1.z * v2.z;
	return (re);
}

t_vec	vec_cro(t_vec v1, t_vec v2)
{
	t_vec re;
	
	re.x = v1.y * v2.z - v2.y * v1.z;
	re.y = v1.z * v2.x - v2.z * v1.x;
	re.z = v1.x * v2.y - v2.x * v1.y;

	return (re);
}

t_vec	vec_plu(t_vec v1, t_vec v2)
{
	t_vec re;
	
	re.x = v1.x + v2.x;
	re.y = v1.y + v2.y;
	re.z = v1.z + v2.z;
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
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

