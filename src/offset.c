/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:56:00 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_2axis	add_offset(t_2v vector, t_prop *prop)
{
	vector.x += prop->tran_x;
	vector.y += prop->tran_y;
	return ((t_2axis){vector.x, vector.y, vector.color});
}

t_2v	scale_mul(t_2v vector, double i)
{
	return ((t_2v){vector.x * i, vector.y * i, vector.color});
}
