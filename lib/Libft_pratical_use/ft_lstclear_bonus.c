/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:41:08 by kawaii            #+#    #+#             */
/*   Updated: 2024/07/17 14:45:38 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **target, void (*del)(void *))
{
	t_list	*cur_node;

	if (!target || !*target || !del)
		return ;
	while (target && *target)
	{
		cur_node = (*target)->next;
		ft_lstdelone(*target, del);
		*target = cur_node;
	}
}
