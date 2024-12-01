/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_limiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:36:35 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	border_bound(t_2axis *ori, t_2axis *end)
{
	if (((ori->x < 0 && end->x < 0) || (ori->x > WIDTH && end->x > WIDTH)))
	{
		return (0);
	}
	if ((ori->y < 0 && end->y < 0) || (ori->y > HEIGHT && end->y > HEIGHT))
	{
		return (0);
	}
	return (1);
}
