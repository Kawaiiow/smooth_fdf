/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:17:05 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/27 20:52:01 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_len(unsigned int num)
{
	int	i;

	i = 0;
	if (!num)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*ft_utoa(unsigned int num)
{
	char	*res;
	int		len;

	len = u_len(num);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (!num)
		res[len] = '0';
	while (num)
	{
		res[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

int	ft_putunbr(unsigned int num)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_utoa(num);
	len += ft_putstr(str);
	free(str);
	return (len);
}
