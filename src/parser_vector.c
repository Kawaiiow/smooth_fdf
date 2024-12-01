/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:17:19 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_3v	parse_value(char **buf, int i, t_map *map)
{
	long	hei;
	char	*hex;
	t_3v	res;

	hei = 0;
	if (ft_strlen(*buf) > 10)
		map->stat = Z_EXCEED;
	else
		hei = ft_atol(*buf);
	res = (t_3v){(int)(i % map->col) - map->col / 2, \
				(int)(i / map->col) - map->row / 2, \
				hei, new_color(WHITE)};
	buf++;
	if (*buf != NULL)
	{
		if ((ft_strlen(*buf) > 2) && (ft_strlen(*buf) <= 10))
		{
			hex = map_up(ft_strchr(*buf, 'x') + 1);
			res.color = new_color(ft_atoi_base(hex, UPP_HEX));
			free(hex);
		}
	}
	return (res);
}

void	init_vector(t_map *map, t_3v *vec_map)
{
	t_row	*cur_row;
	void	*tmp;
	char	**buf;
	char	**split_str;
	int		i;

	i = 0;
	cur_row = map->raw_map;
	while (cur_row != NULL)
	{
		buf = (char **)cur_row->col;
		while (*buf != NULL)
		{
			split_str = ft_split(*buf, ',');
			vec_map[i] = parse_value(split_str, i, map);
			split_clear(split_str);
			buf++;
			i++;
		}
		split_clear(cur_row->col);
		tmp = cur_row;
		cur_row = cur_row->next_row;
		free(tmp);
	}
}
