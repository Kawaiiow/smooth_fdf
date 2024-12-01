/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:19:20 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/27 21:00:42 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

# define LOW_HEX "0123456789abcdef"
# define UPP_HEX "0123456789ABCDEF"

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int num);
int		ft_puthex(unsigned int num, char formatter);
int		ft_putunbr(unsigned int num);
int		ft_putptr(uintptr_t ptr);

int		ft_printf(const char *format, ...);
int		formatter(va_list varg, char format);

#endif