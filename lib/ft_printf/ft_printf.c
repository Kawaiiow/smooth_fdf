/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:23:41 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/27 15:52:54 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	lst_var;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(lst_var, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += formatter(lst_var, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(lst_var);
	return (len);
}
