/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:38:54 by minsuki2          #+#    #+#             */
/*   Updated: 2022/10/26 13:09:56 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "minirt.h"
#include "my_func.h"
#include "get_next_line.h"
#include "minirt_mandatory.h"
#include "draw_func.h"
#include "mlx_key_func.h"
#include "put_func.h"
#include "mlx.h"

void	info_error(int *form_check)
{
	if (form_check[A] != 1)
		ft_strerror("err: wrong ambeint format");
	if (form_check[L] < 1)
		ft_strerror("err: wrong light format");
	if (form_check[C] < 1)
		ft_strerror("err: wrong camera format");
}

void	ft_draw(t_info *info, t_mlx *mlx)
{
	t_color		color;
	t_record	rec;
	int			idx[2];
	double		vdx[2];

	idx[Y] = -1;
	while (++idx[Y] < WIN_H)
	{
		idx[X] = -1;
		while (++idx[X] < WIN_W)
		{
			vdx[U] = (double)idx[X] / (WIN_W - 1);
			vdx[V] = (double)idx[Y] / (WIN_H - 1);
			set_ray_vec(&rec.ray, info->cam, vdx);
			color = cur_point_color(info, &rec);
			my_mlx_pixel_put(&mlx->img, idx[X], (WIN_H - 1 - idx[Y]), color);
		}
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		ft_strerror("err: wrong arguments");
	ft_memset(&info, 0, sizeof(t_info));
	info.mlx.ptr = mlx_init();
	info.mlx.win = mlx_new_window(info.mlx.ptr, WIN_W, WIN_H, "miniRT");
	info.mlx.img.img_ptr = mlx_new_image(info.mlx.ptr, IMG_W, IMG_H);
	info.mlx.img.addr = mlx_get_data_addr(info.mlx.img.img_ptr, \
											&(info.mlx.img.bits_per_pixel), \
											&(info.mlx.img.line_length), \
											&(info.mlx.img.endian));
	info_init(&info, argv[1]);
	ft_draw(&info, &info.mlx);
	mlx_put_image_to_window(info.mlx.ptr, info.mlx.win, \
							info.mlx.img.img_ptr, 0, 0);
	mlx_hook(info.mlx.win, EVENT_KEY_PRESS, 0, key_compatible_param, &info);
	mlx_hook(info.mlx.win, EVENT_MOUSE_CLICK, 0, mouse_compatible_param, &info);
	mlx_hook(info.mlx.win, EVENT_CLICK_EXIT, 0, exit_compatible_param, &info);
	mlx_loop(info.mlx.ptr);
	return (0);
}
