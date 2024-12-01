/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:34:55 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/14 13:55:55 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

/**
 * @brief multiply 3 dimension vector with 3x3 matrix
 * 
 * @param	mat An operand 3x3 matrix
 * @param	vec A pointer operator of 3 dimension vector which will be multiply
 * 
 * @return This function won't return value because since
 * it'll assign to the pointer of operator direcly
 * 
 */
void	ft_3vto3x3(t_3x3_m mat, t_3v *vec)
{
	t_3v	ops;

	ops = (t_3v){vec->x, vec->y, vec->z, new_color(0x0)};
	vec->x = ops.x * mat.i.x + ops.y * mat.i.y + ops.z * mat.i.z;
	vec->y = ops.x * mat.j.x + ops.y * mat.j.y + ops.z * mat.j.z;
	vec->z = ops.x * mat.k.x + ops.y * mat.k.y + ops.z * mat.k.z;
}

/**
 * @brief Multiply integer into vector
 * 
 * @param	*vec A pointer of operator vector
 * @param	c A `double` number of operand
 * 
 * @return This function won't return value because since
 * it'll assign to the pointer of operator direcly
 * 
 */
void	ft_itovec(t_3v *vec, double c)
{
	vec->x *= c;
	vec->y *= c;
	vec->z *= c;
}

/**
 * @brief function for create a rotaion matrix for isometric
 * 
 * @param	degree An angle of rotation
 * @param	axis Enum of rotation axis (X, Y, Z)
 * 
 * @return 3x3 matrix
 * 
 */
t_3x3_m	iso_rotate_m(double degree, t_axis axis)
{
	t_3x3_m	r_m;

	r_m = (t_3x3_m){(t_3v){1, 0, 0, new_color(0x0)}, \
					(t_3v){0, 1, 0, new_color(0x0)}, \
					(t_3v){0, 0, 1, new_color(0x0)}};
	if (axis == X)
	{
		r_m.j = (t_3v){0, cos(degree), -sin(degree), new_color(0x0)};
		r_m.k = (t_3v){0, sin(degree), cos(degree), new_color(0x0)};
	}
	else if (axis == Y)
	{
		r_m.i = (t_3v){cos(degree), 0, sin(degree), new_color(0x0)};
		r_m.k = (t_3v){-sin(degree), 0, cos(degree), new_color(0x0)};
	}
	else if (axis == Z)
	{
		r_m.i = (t_3v){cos(degree), sin(degree), 0, new_color(0x0)};
		r_m.j = (t_3v){-sin(degree), cos(degree), 0, new_color(0x0)};
	}
	return (r_m);
}
