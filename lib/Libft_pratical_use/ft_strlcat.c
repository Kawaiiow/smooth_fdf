/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:03:17 by kawaii            #+#    #+#             */
/*   Updated: 2024/08/26 18:50:21 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, char const *src, size_t size)
{
	register char	*d;
	register char	*s;
	size_t			buffer_left;
	size_t			dest_len;

	d = (char *)dest;
	s = (char *)src;
	buffer_left = size;
	while (buffer_left-- != 0 && *d)
		d++;
	dest_len = d - dest;
	buffer_left = size - dest_len;
	if (!buffer_left)
		return (dest_len + ft_strlen(s));
	while (*s != '\0')
	{
		if (buffer_left != 1)
		{
			*d++ = *s;
			buffer_left--;
		}
		s++;
	}
	*d = '\0';
	return (dest_len + (s - src));
}
