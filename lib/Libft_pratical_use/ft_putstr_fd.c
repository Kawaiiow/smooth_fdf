/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:20:28 by kawaii            #+#    #+#             */
/*   Updated: 2024/09/19 18:52:39 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fildes)
{
	if (!str || fildes < 0)
		return ;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fildes);
		str++;
	}
}
