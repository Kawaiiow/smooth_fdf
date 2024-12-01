/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:54:42 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// render without memorization
// void	render(t_fdf *fdf, t_prop *prop, t_map *map)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < (size_t)(map->row * map->col))
// 	{
// 		if (i % map->col < (size_t)(map->col - 1))
// 		{
// 			plot_line(fdf, \
// 						add_offset(scale_mul(ft_iso(map->vec_map[i], prop) \
// 						, prop->scale), prop), \
// 					add_offset(scale_mul(ft_iso(map->vec_map[i + 1], prop), \
// 						prop->scale), prop));
// 		}
// 		if (i / map->col < (size_t)(map->row - 1))
// 		{
// 			plot_line(fdf, \
// 						add_offset(scale_mul(ft_iso(map->vec_map[i], prop) \
// 						, prop->scale), prop), \
// 					add_offset(scale_mul(ft_iso(map->vec_map[i + map->col], \
// 						prop), prop->scale), prop));
// 		}
// 		i++;
// 	}
// }

static void	init_p(t_map *map, t_2axis *p_buf)
{
	size_t	i;

	i = 0;
	while (i < (size_t)(map->col * map->row))
		p_buf[i++] = (t_2axis){0, 0, new_color(0x0)};
}

static t_2axis	cal_point(t_prop *prop, t_map *map, t_2axis *p_buf, size_t i)
{
	if (p_buf != NULL && p_buf[i].color.rgb_hex)
		return (p_buf[i]);
	else
		p_buf[i] = add_offset(scale_mul(ft_iso(map->vec_map[i], prop) \
					, prop->scale), prop);
	return (p_buf[i]);
}

static void	backward_render(t_fdf *fdf, t_prop *prop, t_map *map)
{
	size_t	i;

	i = (map->row * map->col) - 1;
	if (map->point_buf != NULL)
		init_p(map, map->point_buf);
	while (i > 0)
	{
		if (i % map->col > 0)
			plot_line(fdf, cal_point(prop, map, map->point_buf, i - 1), \
						cal_point(prop, map, map->point_buf, i));
		if (i / map->col > 0)
			plot_line(fdf, cal_point(prop, map, map->point_buf, i - map->col), \
						cal_point(prop, map, map->point_buf, i));
		i--;
	}
}

static void	forward_render(t_fdf *fdf, t_prop *prop, t_map *map)
{
	size_t	i;

	i = 0;
	init_p(map, map->point_buf);
	while (i < (size_t)(map->row * map->col))
	{
		if (i % map->col < (size_t)(map->col - 1))
			plot_line(fdf, cal_point(prop, map, map->point_buf, i), \
						cal_point(prop, map, map->point_buf, i + 1));
		if (i / map->col < (size_t)(map->row - 1))
			plot_line(fdf, cal_point(prop, map, map->point_buf, i), \
						cal_point(prop, map, map->point_buf, i + map->col));
		i++;
	}
}

void	render(t_fdf *fdf, t_prop *prop, t_map *map)
{
	if ((prop->z_deg >= -90 && prop->z_deg < 90) || \
		(prop->z_deg <= -270 || prop->z_deg >= 270))
		forward_render(fdf, prop, map);
	else
		backward_render(fdf, prop, map);
}
