/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:40:40 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:17:07 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*map_up(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
