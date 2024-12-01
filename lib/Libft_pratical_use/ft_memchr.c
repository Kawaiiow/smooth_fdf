/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:04:32 by kawaii            #+#    #+#             */
/*   Updated: 2024/09/19 13:13:46 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*target;
	unsigned char	cmp;

	if (!src)
		return (NULL);
	i = 0;
	target = (unsigned char *)src;
	cmp = (unsigned char)c;
	while (i < n)
	{
		if (target[i] == cmp)
			return (((unsigned char *)src) + i);
		i++;
	}
	return (NULL);
}
