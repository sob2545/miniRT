#include "minirt.h"

t_vector	convert_color_to_normal(int	color)
{
	t_vector	res;

	res.x = color >> 16 & 0xFF;
	res.y = color >> 8 & 0xFF;
	res.z = color & 0xFF;
	if ((res.x == 0 && res.y == 0 && res.z == 0))
		ft_strerror("err: worng bump map");
	res = vec_div_const(res, 255);
	res = vec_sub(vec_mul_const(res, 2), vec_init(1, 1, 1));
	return (res);
}

int	convert_color(t_vector clr)
{
	int pow16[2];
	int	res;

	pow16[X] = 16 * 16 * 16 * 16;
	pow16[Y] = 16 * 16;
	res = ((int)clr.x * pow16[X]) + ((int)clr.y * pow16[Y]) + (int)(clr.z);
	return (res);
}


void	flip_normal_face(t_ray ray, t_moment *spot)
{
	spot->front_face = vec_dot(ray.dir, spot->normal) < 0;
	if (spot->front_face == 0)
		spot->normal = vec_mul_const(spot->normal, -1);
	//front_face를 현재 쓰는 곳이 없음 리팩토링할 때 판단하기 바람.
	return ;
}
