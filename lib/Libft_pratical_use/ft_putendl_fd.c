/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:19:33 by kawaii            #+#    #+#             */
/*   Updated: 2024/06/28 21:20:24 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fildes)
{
	if (!str || fildes < 0)
		return ;
	ft_putstr_fd(str, fildes);
	ft_putchar_fd('\n', fildes);
}
