/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:24:10 by kawaii            #+#    #+#             */
/*   Updated: 2024/07/16 23:28:16 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	char			*res;
	int				len;
	unsigned int	number;

	len = ft_numlen(num);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len--] = '\0';
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		number = num * -1;
		res[0] = '-';
	}
	else
		number = num;
	while (number > 0)
	{
		res[len--] = (number % 10) + '0';
		number /= 10;
	}
	return (res);
}
