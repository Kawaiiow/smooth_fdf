/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:14:05 by pibasri           #+#    #+#             */
/*   Updated: 2024/11/20 12:48:21 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_status(t_state *status, int fildes)
{
	status->fildes = fildes;
	status->offset = 0;
}

char	*get_next_line(int fildes)
{
	static t_state	status[LIMIT];
	char			*res;

	if (fildes < 0 || fildes > LIMIT || status[fildes].eof
		|| status[fildes].fin)
		return (NULL);
	if (!status[fildes].cur_queue)
		init_status(&status[fildes], fildes);
	status[fildes].len_to_newline = 0;
	read_until_newline(&status[fildes]);
	if (status[fildes].len_to_newline == 0
		|| status[fildes].cur_queue->len == (size_t) -1)
	{
		free(status[fildes].cur_queue);
		status[fildes].fin = 1;
		return (NULL);
	}
	res = (char *)malloc((status[fildes].len_to_newline + 1) * sizeof(char));
	if (!res)
		return (NULL);
	return_line_to_buf(&status[fildes], res);
	res[status[fildes].len_to_newline] = '\0';
	return (res);
}
