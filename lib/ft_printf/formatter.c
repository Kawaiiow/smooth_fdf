/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:19:34 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/28 22:35:06 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formatter(va_list varg, char formatter)
{
	int	len;

	len = 0;
	if (formatter == 'c')
		len += ft_putchar(va_arg(varg, int));
	else if (formatter == 's')
		len += ft_putstr(va_arg(varg, char *));
	else if (formatter == 'd' || formatter == 'i')
		len += ft_putnbr(va_arg(varg, int));
	else if (formatter == 'u')
		len += ft_putunbr(va_arg(varg, unsigned int));
	else if (formatter == 'x' || formatter == 'X')
		len += ft_puthex(va_arg(varg, unsigned int), formatter);
	else if (formatter == 'p')
		len += ft_putptr(va_arg(varg, uintptr_t));
	else if (formatter == '%')
		len += ft_putchar('%');
	return (len);
}
