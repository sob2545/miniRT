/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:34:56 by sesim             #+#    #+#             */
/*   Updated: 2022/10/21 17:07:54 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "my_func.h"
#include "rotation_func.h"
#include "mlx.h"
#include "minirt.h"

// void	rot_z_axis(t_vector *normal, double theta)
// {
// 	double	x;
// 	double	y;

// 	x = normal->x;
// 	y = normal->y;
// 	normal->x = x * cos(theta * M_PI / 180) - y * sin(theta * M_PI / 180);
// 	normal->y = x * sin(theta * M_PI / 180) + y * cos(theta * M_PI / 180);
// }

// void	rot_y_axis(t_vector *normal, double theta)
// {
// 	double	z;
// 	double	x;

// 	z = normal->z;
// 	x = normal->x;
	
// 	normal->x = x * cos(theta * M_PI / 180) + z * sin(theta * M_PI / 180);
// 	normal->z = -x * sin(theta * M_PI / 180) + z * cos(theta * M_PI / 180);
// }

void	rot_x_axis(t_vector *normal, double theta)
{
	double	y;
	double	z;

	y = normal->y;
	z = normal->z;
	normal->y = y * cos(theta * M_PI / 180) - z * sin(theta * M_PI / 180);
	normal->z = y * sin(theta * M_PI / 180) + z * cos(theta * M_PI / 180);
}

int	is_rotate_key(int key)
{
	return (key == KEY_UP || key == KEY_DOWN \
			|| key == KEY_LEFT || key == KEY_RIGHT \
			|| key == KEY_COMMA || key == KEY_DOT);
}

int	is_translate_key(int key)
{
	return (key == KEY_W || key == KEY_S \
			|| key == KEY_A || key == KEY_D \
			|| key == KEY_SPC || key == KEY_C);
}

static void	_change_camera(t_info *info, int key)
{
	// if (info->type != CAM_MODE)
	// 	return ;
	if (key == KEY_E)
		info->camera = info->camera->next;
	else if (key == KEY_Q)
		info->camera = info->camera->prev;
}

// static void	_change_object(t_info *info, int key)
// {
// 	if (info->type != EDIT_MODE)
// 		reutrn ;
// 	if (key == KEY_E)
// 		info->camera = info->camera->next;
// 	else if (key == KEY_Q)
// 		info->camera = info->camera->prev;
// 	_translate_object(info->object)
// }

static void	_translate_camera(t_camera *cam, int key)
{
	// if (key != KEY_W && key != KEY_A && key != KEY_S && key != KEY_D && \
	// 		key != KEY_SPC && key != KEY_CTRL)
	// 	return ;
	cam->orig.z -= (key == KEY_W) * WEIGHT_VAL_TRANSLATED_CAM;
	cam->orig.z += (key == KEY_S) * WEIGHT_VAL_TRANSLATED_CAM;
	cam->orig.x -= (key == KEY_A) * WEIGHT_VAL_TRANSLATED_CAM;
	cam->orig.x += (key == KEY_D) * WEIGHT_VAL_TRANSLATED_CAM;
	cam->orig.y += (key == KEY_SPC) * WEIGHT_VAL_TRANSLATED_CAM;
	cam->orig.y -= (key == KEY_CTRL) * WEIGHT_VAL_TRANSLATED_CAM;

	
	if (key == KEY_UP)
		q_rotation(cam, 30.0, PITCH);
	else if (key == KEY_DOWN)
		q_rotation(cam, -30.0, PITCH);
	else if (key == KEY_LEFT)
		rot_x_axis(&cam->normal, -30);
	else if (key == KEY_RIGHT)
		rot_x_axis(&cam->normal, 30);
	printf("normal : %lf %lf %lf\n", cam->normal.x, cam->normal.y, cam->normal.z);
	// else if (key == KEY_COMMA)
	// 	rot_y_axis(&cam->normal, -30);
	// else if (key == KEY_DOT)
	// 	rot_y_axis(&cam->normal, 30);
	if (is_translate_key(key) || is_rotate_key(key))
		set_mlx_vector_r_half(cam->mlx_vec, cam->normal, cam->viewport);

	// cam->normal.y += (key == KEY_UP) * WEIGHT_VAL_ROTATED_CAM;
	// cam->normal.y -= (key == KEY_DOWN) * WEIGHT_VAL_ROTATED_CAM;
	// cam->normal.x -= (key == KEY_LEFT) * WEIGHT_VAL_ROTATED_CAM;
	// cam->normal.x -= (key == KEY_DOWN) * WEIGHT_VAL_ROTATED_CAM;
	// cam->normal.x += 2 * (cam->normal.y < -1) - 2 * (cam->normal.y > 1);
	// cam->normal.y += 2 * (cam->normal.y < -1) - 2 * (cam->normal.y > 1);
	// cam->normal.z += 2 * (cam->normal.y < -1) - 2 * (cam->normal.y > 1);
	cam->start_point = vec_once_add_point(cam->orig, \
									&cam->mlx_vec[R_HALF][HORI], \
									&cam->mlx_vec[R_HALF][VERT], &cam->normal);
}

void	key_event(t_info *info, int key)
{
	_change_camera(info, key);
	_translate_camera(info->camera, key);
	// _change_object(info, key);
}

