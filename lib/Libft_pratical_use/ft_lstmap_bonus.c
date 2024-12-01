/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:10:34 by pibasri           #+#    #+#             */
/*   Updated: 2024/08/27 19:46:18 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *target, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*res;

	if (!target || !f || !del)
		return (0);
	new_lst = ft_lstnew(f(target->content));
	if (!new_lst)
		return (0);
	res = new_lst;
	target = target->next;
	while (target)
	{
		new_lst->next = ft_lstnew(f(target->content));
		if (!new_lst->next)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		new_lst = new_lst->next;
		target = target->next;
	}
	new_lst->next = NULL;
	return (res);
}
