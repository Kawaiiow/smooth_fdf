/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:20:04 by kawaii            #+#    #+#             */
/*   Updated: 2024/09/19 13:09:31 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *target, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!target)
		return ;
	str = target;
	while (i < n)
		str[i++] = 0;
}
