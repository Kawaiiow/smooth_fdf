/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:39:54 by kawaii            #+#    #+#             */
/*   Updated: 2024/08/25 18:44:31 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	app_str(char *src, char *dest, unsigned int i)
{
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		len;
	char	*res;

	len = 0;
	if (!str1 || !str2)
		return (NULL);
	res = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1)
			* sizeof(char));
	if (res == NULL)
		return (NULL);
	len = app_str((char *)str1, res, len);
	len = app_str((char *)str2, res, len);
	res[len] = '\0';
	return (res);
}
