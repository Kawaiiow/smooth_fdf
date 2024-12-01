/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:10:08 by kawaii            #+#    #+#             */
/*   Updated: 2024/08/26 16:58:19 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	size_t			i;
	unsigned char	t;

	i = 0;
	t = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == t)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == t)
		return ((char *) &str[i]);
	return (0);
}
