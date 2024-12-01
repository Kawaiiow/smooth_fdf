/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:54:55 by kawaii            #+#    #+#             */
/*   Updated: 2024/09/19 12:46:24 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0' || to_find == str || !to_find)
		return ((char *) str);
	if (!n)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] && i + j < n)
		{
			j++;
			if (to_find[j] == '\0')
				return (((char *)str) + i);
		}
		i++;
	}
	return (0);
}
