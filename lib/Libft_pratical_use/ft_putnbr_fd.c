/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:56:58 by kawaii            #+#    #+#             */
/*   Updated: 2024/06/28 21:21:03 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fildes)
{
	long	num;

	num = n;
	if (fildes < 0)
		return ;
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', fildes);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fildes);
		ft_putnbr_fd(num % 10, fildes);
	}
	else
		ft_putchar_fd(num + '0', fildes);
}
