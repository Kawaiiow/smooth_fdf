/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:24:39 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/28 22:12:58 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static char	*ft_itohex(unsigned int num, char *set)
{
	int				len;
	unsigned long	number;
	char			*res;

	len = hex_len(num);
	number = num;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (!num)
		res[len] = '0';
	while (number > 0)
	{
		res[len--] = set[number % 16];
		number /= 16;
	}
	return (res);
}

int	ft_puthex(unsigned int num, char formatter)
{
	char	*str;
	int		len;

	len = 0;
	str = NULL;
	if (formatter == 'x')
		str = ft_itohex(num, LOW_HEX);
	else if (formatter == 'X')
		str = ft_itohex(num, UPP_HEX);
	len += ft_putstr(str);
	free(str);
	return (len);
}
