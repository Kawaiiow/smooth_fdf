/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:37:03 by pibasri           #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static double	fraction(float n1, float n2, float axis)
{
	if (n1 != n2)
		return ((axis - n1) / (n2 - n1));
	return (0);
}

int	gradient(t_2axis *cur_pos, t_2axis *start, t_2axis *stop)
{
	int		dx;
	int		dy;
	double	scale;
	t_color	new_color;

	dx = abs(stop->x - start->x);
	dy = abs(stop->y - start->y);
	if (dx > dy)
		scale = fraction(start->x, stop->x, cur_pos->x);
	else
		scale = fraction(start->y, stop->y, cur_pos->y);
	new_color.r = start->color.r + (stop->color.r - start->color.r) * scale;
	new_color.g = start->color.g + (stop->color.g - start->color.g) * scale;
	new_color.b = start->color.b + (stop->color.b - start->color.b) * scale;
	new_color.a = start->color.a + (stop->color.a - start->color.a) * scale;
	return (new_color.rgb_hex);
}
