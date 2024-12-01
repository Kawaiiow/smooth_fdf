/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:55:39 by pibasri           #+#    #+#             */
/*   Updated: 2024/11/17 10:51:49 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef LIMIT
#  define LIMIT 1024
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_queue
{
	char			content[BUFFER_SIZE];
	size_t			len;
	struct s_queue	*next_queue;
}	t_queue;

typedef struct s_state
{
	int		fildes;
	int		eof;
	int		fin;
	t_queue	*cur_queue;
	t_queue	*pre_queue;
	size_t	offset;
	size_t	len_to_newline;
}	t_state;

char	*get_next_line(int fd);

void	read_buffer(t_state *r);
void	read_until_newline(t_state *prop);
void	return_line_to_buf(t_state *prop, char *res);

#endif
