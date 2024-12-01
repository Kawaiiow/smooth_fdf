/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:32:27 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/27 20:48:07 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_len(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int num)
{
	int				len;
	unsigned int	u_num;
	char			*res;

	len = n_len(num);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (!num)
		res[0] = '0';
	if (num < 0)
	{
		u_num = num * -1;
		res[0] = '-';
	}
	else
		u_num = num;
	while (u_num > 0)
	{
		res[len--] = (u_num % 10) + '0';
		u_num /= 10;
	}
	return (res);
}

int	ft_putnbr(int num)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(num);
	len += ft_putstr(str);
	free(str);
	return (len);
}
