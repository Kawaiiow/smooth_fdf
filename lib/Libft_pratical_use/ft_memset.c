/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:45:02 by kawaii            #+#    #+#             */
/*   Updated: 2024/09/19 13:17:25 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
		str[i++] = chr;
	return (s);
}
