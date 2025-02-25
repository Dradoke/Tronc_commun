/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:43:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/25 17:48:29 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	add_shade(double distance, int color)
{
	if (distance == 0)
		return (color);
	else if (distance == 1)
		return (255 << 24 | color);
	else if (distance == 0.5)
		return ((255 / 2) << 24 | color);
	else if (distance == 0.25)
		return ((255 / 4) << 24 | color);
	else
		return (1);
}

int	get_oposite(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	return (create_trgb(t, b, r, g));
}

unsigned int	bld_clr(t_n_l line, t_line_pts line_pts, t_image *img, char tb)
{
	unsigned int	bg[2];
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			alpha;

	bg[0] = *((unsigned int *)(line.ost + img->px_ptr));
	bg[1] = line_pts.start.color;
	if (tb == 't')
		alpha = 1 - line.dist;
	else
	{
		alpha = line.dist;
	}
	r = ((bg[0] >> 16) & 0xFF) * (1 - alpha) + ((bg[1] >> 16) & 0xFF) * alpha;
	g = ((bg[0] >> 8) & 0xFF) * (1 - alpha) + ((bg[1] >> 8) & 0xFF) * alpha;
	b = (bg[0] & 0xFF) * (1 - alpha) + (bg[1] & 0xFF) * alpha;
	return ((r << 16) | (g << 8) | b);
}
