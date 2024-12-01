/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:27:04 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:16:43 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	break_atoi(char n, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (n == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	error_catch(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '\f' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '-' || base[i] == '+')
			return (1);
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base [j])
				return (1);
		}
		i++;
	}
	return (0);
}

static int	base_convert(char *str, char *base)
{
	int	i;
	int	res;
	int	ops;
	int	base_len;

	i = 0;
	ops = 0;
	res = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	while (str[i])
	{
		ops = break_atoi(str[i], base);
		if (ops == -1)
			return (res);
		res *= base_len;
		res += ops;
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;

	sign = 1;
	if (error_catch(base) == 1)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 14))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	return (base_convert(str, base) * sign);
}
