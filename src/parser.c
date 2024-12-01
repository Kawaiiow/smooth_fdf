/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:10:37 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_map(t_map *map)
{
	map->stat = A_OK;
	map->col = 0;
	map->row = 0;
	map->raw_map = NULL;
	map->cur_row = NULL;
	map->vec_map = NULL;
	map->point_buf = NULL;
}

void	clear_queue_split(t_row *raw_map)
{
	t_row	*tmp;

	while (raw_map != NULL)
	{
		tmp = raw_map;
		split_clear(raw_map->col);
		raw_map = raw_map->next_row;
		free(tmp);
	}
}

int	open_map(int *fd, int argc, char **argv, t_map *map)
{
	if (argc != 2 || ft_strlen(ft_strrchr(argv[1], '.')) != 4 \
		|| ft_strncmp(ft_strrchr(argv[1], '.'), ".fdf", 4))
	{
		map->stat = CON_ERROR;
		return (0);
	}
	*fd = open(argv[1], 0400);
	if (*fd < 0)
	{
		map->stat = CON_ERROR;
		return (0);
	}
	return (1);
}

void	read_map(t_map *map, int argc, char **argv)
{
	int		fd;

	if (!open_map(&fd, argc, argv, map))
		return ;
	init_map(map);
	get_queue(map, fd);
	close(fd);
	if (map->col < 2 || map->row < 2)
		map->stat = CON_ERROR;
	if (map->stat == CON_ERROR)
		return (clear_queue(map->raw_map, free));
	lst_iter(map->raw_map);
	map->vec_map = (t_3v *)malloc((map->col * map->row) * sizeof(t_3v));
	if (!map->vec_map)
		return (clear_queue_split(map->raw_map));
	init_vector(map, map->vec_map);
	if (map->stat == Z_EXCEED)
		return (free(map->vec_map));
	map->point_buf = (t_2axis *)malloc(map->col * map->row * sizeof(t_2axis));
	map->stat = A_OK;
}
