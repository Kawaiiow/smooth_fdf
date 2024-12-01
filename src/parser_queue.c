/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:54 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	valid_str(char *str, int *col)
{
	int	wpl;

	wpl = 1;
	while (*str != '\0' && (in(*str, " -abcdefABCDEFx,")
			|| ft_isdigit(*str)))
	{
		while (ft_isdigit(*str) || in(*str, "-abcdefABCDEFx,"))
			str++;
		if (*str == ' ')
			wpl++;
		while (*str == ' ')
			str++;
	}
	if (!*col && wpl > 1 && (*str == '\0' || *str == '\n'))
		*col = wpl;
	else if (*col != wpl || (*str != '\0' && *str != '\n'))
		return (0);
	return (1);
}

void	clear_queue(t_row *raw_map, void (*f)(void *))
{
	t_row	*tmp;

	while (raw_map != NULL)
	{
		f(raw_map->col);
		tmp = raw_map;
		raw_map = raw_map->next_row;
		free(tmp);
	}
}

static void	add_to_queue(char *buf, t_map *map)
{
	if (!map->raw_map)
	{
		map->raw_map = malloc(sizeof(t_row));
		if (!map->raw_map)
			return ;
		map->raw_map->col = ft_strdup(buf);
		map->raw_map->next_row = NULL;
		map->cur_row = map->raw_map;
	}
	else
	{
		map->cur_row->next_row = malloc(sizeof(t_row));
		if (!map->cur_row->next_row)
			return ;
		map->cur_row = map->cur_row->next_row;
		map->cur_row->col = ft_strdup(buf);
		map->cur_row->next_row = NULL;
	}
}

void	lst_iter(t_row *row)
{
	t_row	*cur_row;
	void	*tmp;

	cur_row = row;
	while (cur_row != NULL)
	{
		tmp = cur_row->col;
		cur_row->col = (char **)ft_split((char *)cur_row->col, ' ');
		cur_row = cur_row->next_row;
		free(tmp);
	}
}

void	get_queue(t_map *map, int fd)
{
	char	*buf;
	void	*tmp;

	buf = get_next_line(fd);
	while (buf != NULL)
	{
		tmp = buf;
		buf = ft_strtrim(buf, " \n");
		free(tmp);
		if (!valid_str(buf, &map->col))
			map->stat = CON_ERROR;
		add_to_queue(buf, map);
		free(buf);
		buf = get_next_line(fd);
		map->row++;
	}
}
