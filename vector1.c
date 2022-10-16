/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:30:30 by sesim             #+#    #+#             */
/*   Updated: 2022/10/16 18:36:24 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vec_add(t_vector u, t_vector v)
{
	t_vector	init;

	init.x = u.x + v.x;
	init.y = u.y + v.y;
	init.z = u.z + v.z;
	return (init);
}

t_vector	vec_sub(t_vector u, t_vector v)
{
	t_vector	init;

	init.x = u.x - v.x;
	init.y = u.y - v.y;
	init.z = u.z - v.z;
	return (init);
}

t_vector	vec_mul(t_vector u, t_vector v)
{
	t_vector	init;

	init.x = u.x * v.x;
	init.y = u.y * v.y;
	init.z = u.z * v.z;
	return (init);
}

t_vector	vec_div(t_vector u, t_vector v)
{
	t_vector	init;

	if (v.x == 0 || v.y == 0 || v.z == 0)
		ft_strerror("0 넣지마");
	init.x = u.x / v.x;
	init.y = u.y / v.y;
	init.z = u.z / v.z;
	return (init);
}

t_vector	vec_init(double x, double y, double z)
{
	t_vector	init;

	init.x = x;
	init.y = y;
	init.z = z;
	return (init);
}
