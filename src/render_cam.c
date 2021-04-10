#include "minirt.h"

void		cam_set(t_world **world,t_cam *camera)
{
	double theta;

	theta = make_degrees(camera->fov);
	camera->view_h = 2.0 * tan(theta / 2.0);
	camera->view_w = (*world)->resolution.x/(*world)->resolution.y * camera->view_h;
	camera->focal_lenght = camera->look_from.z;
	camera->w = vec_unit(vec_sub((camera->look_from), camera->look_at));
	camera->u = vec_unit(vec_cro(check_vup(vec_make(0.0, 1.0, 0.0), camera->look_at), camera->w));
	camera->v = vec_unit(vec_cro(camera->w,camera->u));
	camera->horizontal = vec_mul(camera->u, camera->view_w);
	camera->vertical = vec_mul(camera->v, camera->view_h);
	//camera->lower_left_corner = vec_sub(vec_sub(vec_sub((camera->look_from), vec_mul(camera->horizontal, 0.5)), vec_mul(camera->vertical, 0.5)), camera->w);
	camera->lower_left_corner = vec_sub(vec_sub(vec_sub(camera->look_from, vec_mul(camera->horizontal, 0.5)), vec_mul(camera->vertical, 0.5)), camera->w);

	camera->lower_left_corner = vec_make((camera->look_from.x - camera->horizontal.x/2.0 - camera->vertical.x/2.0 - camera->w.x),
	(camera->look_from.y - camera->horizontal.y/2.0 - camera->vertical.y/2.0 - camera->w.y), 
	(camera->look_from.z - camera->horizontal.z/2.0 - camera->vertical.z/2.0 - camera->w.z));
		
}