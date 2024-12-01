/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:54:38 by pibasri           #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	mirror(int *diff, int *inc)
{
	if (*diff < 0)
	{
		*inc = -1;
		*diff = -*diff;
	}
}

static void	x_line(t_fdf *fdf, t_2axis *start, t_2axis *stop)
{
	int		dx;
	int		dy;
	int		inc;
	int		diff;
	t_2axis	pos;

	inc = 1;
	dx = stop->x - start->x;
	dy = stop->y - start->y;
	mirror(&dy, &inc);
	diff = (2 * dy) - dx;
	pos = *start;
	while (pos.x < stop-> x)
	{
		if (pos.x > 0 && pos.y > 0 && pos.x < WIDTH && pos.y < HEIGHT)
			mlx_put_pixel(fdf->img, pos.x, pos.y, gradient(&pos, start, stop));
		if (diff > 0)
		{
			pos.y += inc;
			diff += 2 * (dy - dx);
		}
		else
			diff += 2 * dy;
		pos.x++;
	}
}

static void	y_line(t_fdf *fdf, t_2axis *start, t_2axis *stop)
{
	int		dx;
	int		dy;
	int		inc;
	int		diff;
	t_2axis	pos;

	inc = 1;
	dx = stop->x - start->x;
	dy = stop->y - start->y;
	mirror(&dx, &inc);
	diff = (2 * dx) - dy;
	pos = *start;
	while (pos.y < stop->y && pos.y < HEIGHT)
	{
		if (pos.x > 0 && pos.y > 0 && pos.x < WIDTH && pos.y < HEIGHT)
			mlx_put_pixel(fdf->img, pos.x, pos.y, gradient(&pos, start, stop));
		if (diff > 0)
		{
			pos.x += inc;
			diff += 2 * (dx - dy);
		}
		else
			diff += 2 * dx;
		pos.y++;
	}
}

static int	border_bound(t_2axis *ori, t_2axis *end)
{
	if (((ori->x < 0 && end->x < 0) || (ori->x > WIDTH && end->x > WIDTH)))
	{
		return (0);
	}
	if ((ori->y < 0 && end->y < 0) || (ori->y > HEIGHT && end->y > HEIGHT))
	{
		return (0);
	}
	return (1);
}

void	plot_line(t_fdf *fdf, t_2axis start, t_2axis stop)
{
	if (!border_bound(&start, &stop))
		return ;
	if (abs(stop.y - start.y) < abs(stop.x - start.x))
	{
		if (start.x > stop.x)
			x_line(fdf, &stop, &start);
		else
			x_line(fdf, &start, &stop);
	}
	else
	{
		if (start.y > stop.y)
			y_line(fdf, &stop, &start);
		else
			y_line(fdf, &start, &stop);
	}
}
