/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:44:44 by kawaii            #+#    #+#             */
/*   Updated: 2024/08/25 12:09:29 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;

	if (!str)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(str))
	{
		res = (char *)malloc(sizeof(char) * 1);
		ft_strlcpy(res, "\0", 1);
		return (res);
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	str += start;
	res = (char *)malloc(len * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str, len + 1);
	return (res);
}
