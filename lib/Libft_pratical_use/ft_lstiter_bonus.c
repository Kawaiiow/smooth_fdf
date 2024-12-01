/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:49:22 by kawaii            #+#    #+#             */
/*   Updated: 2024/08/27 19:48:07 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *target, void (*f)(void *))
{
	if (!f)
		return ;
	while (target)
	{
		(*f)(target->content);
		target = target->next;
	}
}
