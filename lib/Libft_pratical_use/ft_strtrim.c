/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:37:27 by kawaii            #+#    #+#             */
/*   Updated: 2024/08/25 13:03:18 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	size;
	char	*res;

	if (!str || !set)
		return (NULL);
	while (check_trim(*str, (char *)set) && *str)
		str++;
	size = ft_strlen(str);
	while (check_trim(str[size - 1], (char *)set) && size > 0)
		size--;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)str, size + 1);
	return (res);
}
