/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:09:13 by kawaii            #+#    #+#             */
/*   Updated: 2024/08/28 17:25:40 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **target, t_list *new)
{
	if (target && new)
	{
		if (*target)
			ft_lstlast(*target)->next = new;
		else
			*target = new;
	}
}
