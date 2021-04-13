#include "minirt.h"
t_vec	vup(t_vec v)
{
	if (vec_cos(v, vec_make(0,1,0)) == 1.0)
			return (vec_make(1,0,1));
	else	
		return (vec_make(0,1,0));
}


void		cam_set(t_world **world,t_cam *camera)
{
	double theta;

	theta = make_degrees(camera->fov);
	camera->view_h = 2.0 * tan(theta / 2.0);
	camera->view_w = (double)(*world)->resolution.x/(double)(*world)->resolution.y * (double)camera->view_h;
	//camera->focal_lenght = camera->look_from.z;
	//camera->w = vec_unit(vec_sub(camera->look_from, camera->look_at));
	camera->w = vec_unit(camera->look_at);// ㅇㅣ미 바라보는방향이 되어있으므로 이게 맞다..?

	camera->u = vec_unit(vec_cro(/*vup(camera->look_at*/vec_make(0,1,0), camera->w));
	camera->u = vec_unit(vec_cro(/*vup(camera->look_at*/camera->w, vec_make(0,1,0)));
	
	
	camera->v = vec_unit(vec_cro(camera->w,camera->u));
		camera->v = vec_unit(vec_cro(camera->u,camera->w));

	
	
	//printf("w%f, %f, %f,   u%f, %f, %f,     v%f, %f, %f\n", camera->w.x,camera->w.y,camera->w.z,camera->u.x,camera->u.y,camera->u.z,camera->v.x,camera->v.y,camera->v.z);
	camera->horizontal = vec_mul(camera->u, camera->view_w);
	camera->vertical = vec_mul(camera->v, camera->view_h);
	//printf("hx%f,hy%f,hz%f,vx%f,vy%f,vz%f\n",camera->horizontal.x,camera->horizontal.y,camera->horizontal.z,camera->vertical.x,camera->vertical.y,camera->vertical.z);
	 camera->lower_left_corner = vec_plu(vec_sub(vec_sub(camera->look_from, vec_mul(camera->horizontal, 0.5)), vec_mul(camera->vertical, 0.5)), camera->w);
	// camera->lower_left_corner = vec_make(camera->look_from.x - 0.5* camera->horizontal.x - 0.5 * camera->vertical.x - camera->w.x
	// 									,camera->look_from.y - 0.5* camera->horizontal.y - 0.5 * camera->vertical.y - camera->w.y	
	// 									,camera->look_from.z - 0.5* camera->horizontal.z - 0.5 * camera->vertical.z - camera->w.z	);
}