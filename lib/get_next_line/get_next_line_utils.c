/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:29:44 by pibasri           #+#    #+#             */
/*   Updated: 2024/11/20 12:48:45 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_buffer(t_state *r)
{
	if (!r->cur_queue)
	{
		r->cur_queue = malloc(sizeof(t_queue));
		if (!r->cur_queue)
			return ;
		r->cur_queue->next_queue = NULL;
		r->cur_queue->len = 0;
		r->pre_queue = r->cur_queue;
	}
	else if (!r->eof)
	{
		r->pre_queue->next_queue = malloc(sizeof(t_queue));
		if (!r->pre_queue->next_queue)
			return ;
		r->pre_queue = r->pre_queue->next_queue;
		r->pre_queue->next_queue = NULL;
		r->pre_queue->len = 0;
	}
	else
		return ;
	r->pre_queue->len = read(r->fildes, r->pre_queue->content, BUFFER_SIZE);
	if (r->pre_queue->len == 0)
		r->eof = 1;
}

void	read_until_newline(t_state *prop)
{
	size_t	i;
	t_queue	*queue;

	if (!prop->cur_queue)
		read_buffer(prop);
	queue = prop->cur_queue;
	if (!queue || !prop->pre_queue || prop->pre_queue->len == (size_t) -1)
		return ;
	while (queue->len)
	{
		i = (prop->len_to_newline + prop->offset) % BUFFER_SIZE;
		if (i > (queue->len - 1))
			return ;
		if (queue->content[i] == '\n')
		{
			prop->len_to_newline++;
			return ;
		}
		prop->len_to_newline++;
		if (i == BUFFER_SIZE - 1)
		{
			read_buffer(prop);
			queue = queue->next_queue;
		}
	}
}

void	return_line_to_buf(t_state *prop, char *res)
{
	size_t	i;
	t_queue	*temp;

	i = 0;
	while (i < prop->len_to_newline || prop->cur_queue)
	{
		if (i < prop->len_to_newline)
			res[i] = prop->cur_queue->content[prop->offset];
		prop->offset++;
		i++;
		if (prop->offset == prop->cur_queue->len || !prop->cur_queue->len)
		{
			prop->offset = 0;
			temp = prop->cur_queue;
			prop->cur_queue = prop->cur_queue->next_queue;
			free(temp);
		}
		if (i == prop->len_to_newline && prop->offset)
			return ;
	}
}
