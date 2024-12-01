/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:00:49 by pibasri           #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	init_prop(t_prop *prop)
{
	prop->map = NULL;
	prop->mode = ISO;
	prop->tran_x = WIDTH / 2;
	prop->tran_y = HEIGHT / 2;
	prop->x_deg = 2;
	prop->y_deg = 0;
	prop->z_deg = 45;
	prop->scale = FIX_SCALE;
}

static int	init_mlx_image(t_fdf *fdf)
{
	t_2axis	pos;

	pos.y = 0;
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF(Memorization)", true);
	if (!fdf->mlx)
		return (0);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		return (0);
	while (pos.y < HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WIDTH)
		{
			mlx_put_pixel(fdf->img, pos.x, pos.y, 0xFF);
			pos.x++;
		}
		pos.y++;
	}
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	init_prop(&fdf.prop);
	fdf.prop.map = (t_map *)malloc(sizeof(t_map));
	read_map(fdf.prop.map, argc, argv);
	if (fdf.prop.map->stat != A_OK)
	{
		free(fdf.prop.map);
		return (1);
	}
	if (!init_mlx_image(&fdf))
		exit(EXIT_FAILURE);
	mlx_loop_hook(fdf.mlx, &move_control, &fdf);
	render(&fdf, &fdf.prop, fdf.prop.map);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free(fdf.prop.map->vec_map);
	free(fdf.prop.map->point_buf);
	free(fdf.prop.map);
	return (0);
}
