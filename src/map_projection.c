/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:47:06 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	rad(double degree)
{
	return (degree * (M_PI / 180));
}

t_2v	ft_iso(t_3v vector, t_prop *prop)
{
	double	z_t;

	if (prop->mode == OTH_T)
		ft_3vto3x3(iso_rotate_m(rad(0), Z), &vector);
	else if (prop->mode == OTH_S)
	{
		ft_3vto3x3(iso_rotate_m(rad(90), Y), &vector);
		ft_3vto3x3(iso_rotate_m(rad(90), Z), &vector);
	}
	else if (prop->mode == OTH_F)
	{
		ft_3vto3x3(iso_rotate_m(rad(90), Z), &vector);
		ft_3vto3x3(iso_rotate_m(rad(90), X), &vector);
		ft_3vto3x3(iso_rotate_m(rad(90), Y), &vector);
	}
	else if (prop->mode == ISO)
	{
		z_t = rad(prop->z_deg);
		ft_3vto3x3(iso_rotate_m(z_t, Z), &vector);
		ft_3vto3x3(iso_rotate_m(atan(sqrt(2)), X), &vector);
	}
	return ((t_2v){vector.x, vector.y, vector.color});
}
