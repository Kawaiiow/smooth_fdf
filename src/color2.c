/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:15:37 by kawaii            #+#    #+#             */
/*   Updated: 2024/11/21 21:31:53 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_color	new_color(int hex)
{
	t_color	c;

	c.rgb_hex = hex;
	return (c);
}
