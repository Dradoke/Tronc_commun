/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:43:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/20 17:49:24 by ngaudoui         ###   ########.fr       */
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
unsigned int blend_color(unsigned int bg, unsigned int fg, float alpha)
{
    unsigned char r = ((bg >> 16) & 0xFF) * (1 - alpha) + ((fg >> 16) & 0xFF) * alpha;
    unsigned char g = ((bg >> 8) & 0xFF) * (1 - alpha) + ((fg >> 8) & 0xFF) * alpha;
    unsigned char b = (bg & 0xFF) * (1 - alpha) + (fg & 0xFF) * alpha;
    return (r << 16) | (g << 8) | b;
}
