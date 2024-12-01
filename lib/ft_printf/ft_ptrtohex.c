/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:50:36 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/27 21:11:42 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_iterptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		len += ft_iterptr(ptr / 16);
		len += ft_iterptr(ptr % 16);
	}
	else
		len += ft_putchar(LOW_HEX[ptr]);
	return (len);
}

int	ft_putptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_iterptr(ptr);
	return (len);
}
