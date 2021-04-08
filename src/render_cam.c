#include "minirt.h"

void		cam_set(t_info *info, t_cam *c)
{
	double theta;

	theta = make_degrees(c->r);
	info->v_h = 2.0 * tan(theta / 2.0);
	info->v_w = info->world->r.x/info->world->r.y * info->v_h;
	info->f_l = c->o.z;
	info->ori = c->o;
	info->w = vec_unit(vec_sub((info->ori), c->nv));
	info->u = vec_unit(vec_cro(check_vup(vec_make(0.0, -1.0, 0.0), c->nv), info->w));
	info->v = vec_unit(vec_cro(info->w,info->u));
//	info->hor = vec_make(info->v_w * info->u.x, 0.0, 0.0);
//	info->ver = vec_make(0.0, info->v_h * info->v.y, 0.0);
//	info->llc = vec_make((info->ori.x - info->hor.x/2.0 - info->ver.x/2.0 - info->w.x), (info->ori.y - info->hor.y/2.0 - info->ver.y/2.0 - info->w.y), (info->ori.z - info->hor.z/2.0 - info->ver.z/2.0 - info->w.z));
		printf("%f", c->nv.y);
	info->hor = vec_mul(info->u, info->v_w);
	printf(" xyz:%f,%f,%f ,%f\n ",info->hor.x,info->hor.y,info->hor.z, info->v_w);
	info->ver = vec_mul(info->v, info->v_h);
	info->llc = vec_sub(vec_sub(vec_sub((info->ori), vec_mul(info->hor, 0.5)), vec_mul(info->ver, 0.5)), info->w);
	printf(" xyz:%f,%f,%f ,%f\n ",info->llc.x,info->llc.y,info->llc.z, info->v_w);
//	info->llc = vec_make((info->ori.x - info->hor.p.x/2.0 - info->ver.p.x/2.0 - info->w.p.x), (info->ori.y - info->hor.p.y/2.0 - info->ver.p.y/2.0 - info->w.p.y), (info->ori.z - info->hor.p.z/2.0 - info->ver.p.z/2.0 - info->w.p.z));
	
}