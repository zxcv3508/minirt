#include "minirt.h"

void		cam_set(t_world **world,t_cam *camera)
{
	double theta;

	theta = make_degrees(camera->fov);
	camera->view_h = 2.0 * tan(theta / 2.0);
	camera->view_w = (*world)->resolution.x/(*world)->resolution.y * camera->view_h;
	camera->focal_lenght = camera->look_from.z;
	//camera->look_from = camera->look_from;
	camera->w = vec_unit(vec_sub((camera->look_from), camera->look_at));
	camera->u = vec_unit(vec_cro(check_vup(vec_make(0.0, 1.0, 0.0), camera->look_at), camera->w));
	camera->v = vec_unit(vec_cro(camera->w,camera->u));
//	camera->hor = vec_make(camera->view_w * camera->u.x, 0.0, 0.0);
//	camera->ver = vec_make(0.0, camera->view_h * camera->v.y, 0.0);
//	camera->llc = vec_make((camera->ori.x - camera->hor.x/2.0 - camera->ver.x/2.0 - camera->w.x), (camera->ori.y - camera->hor.y/2.0 - camera->ver.y/2.0 - camera->w.y), (camera->ori.z - camera->hor.z/2.0 - camera->ver.z/2.0 - camera->w.z));
		//printf("%f", camera->ld.y);
	camera->horizontal = vec_mul(camera->u, camera->view_w);
	printf(" xyz:%f,%f,%f ,%f\n ",camera->horizontal.x,camera->horizontal.y,camera->horizontal.z, camera->view_w);
	camera->vertical = vec_mul(camera->v, camera->view_h);
	camera->lower_left_corner = vec_sub(vec_sub(vec_sub((camera->look_from), vec_mul(camera->horizontal, 0.5)), vec_mul(camera->vertical, 0.5)), camera->w);
	printf(" xyz:%f,%f,%f ,%f\n ",camera->lower_left_corner.x,camera->lower_left_corner.y,camera->lower_left_corner.z, camera->view_w);
//	camera->llc = vec_make((camera->ori.x - camera->horizontal.p.x/2.0 - camera->ver.p.x/2.0 - camera->w.p.x), (camera->ori.y - camera->hor.p.y/2.0 - camera->ver.p.y/2.0 - camera->w.p.y), (camera->ori.z - camera->hor.p.z/2.0 - camera->ver.p.z/2.0 - camera->w.p.z));
	
}