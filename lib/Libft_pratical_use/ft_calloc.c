/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:11:15 by kawaii            #+#    #+#             */
/*   Updated: 2024/09/19 13:06:22 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	if (!n || !size)
	{
		res = (void *)malloc(1);
		if (res == NULL)
			return (NULL);
		ft_bzero(res, 1);
		return (res);
	}
	if (size > __INT_MAX__ || n > __INT_MAX__ || n * size > __INT_MAX__)
		return (NULL);
	res = (void *)malloc(n * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, (n * size));
	return (res);
}
