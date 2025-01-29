/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:43:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/01/29 07:50:58 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/bit_shifting.h"

int add_shade(double distance, int color)
{
	if (distance == 0)
		return (color);
	else if (distance == 1)
		return(255 << 24 | color);
	else if (distance == 0.5)
		return((255/2) << 24 | color);
	else if (distance == 0.25)
		return((255/4) << 24 | color);
	else
		return (1);
}
int get_oposite(int color)
{
	int t;
	int r;
	int g;
	int b;

	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	return (create_trgb(t,b,r,g));
}