/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaii <kawaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:24:02 by kawaii            #+#    #+#             */
/*   Updated: 2024/07/17 14:16:36 by kawaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *target)
{
	int		n;
	t_list	*cur_node;

	if (!target)
		return (0);
	n = 1;
	cur_node = target;
	while (cur_node->next != NULL)
	{
		cur_node = cur_node->next;
		n++;
	}
	return (n);
}
