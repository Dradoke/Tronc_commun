/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:43:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/24 15:50:57 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_rgba	itorgb(unsigned int color)
{
	t_rgba	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

int	rgbtoi(t_rgba rgb)
{
	int	color;

	color = ((int)rgb.r << 16) | ((int)rgb.g << 8) | (int)rgb.b;
	return (color);
}

t_rgba	gradient(t_line_pts l)
{
	int		len;

	if (l.d.sx > l.d.sy)
		len = l.d.sx;
	else
		len = c_abs(l.d.sy);
	l.index.color.r += (l.end.color.r - l.start.color.r) / len;
	l.index.color.g += (l.end.color.g - l.start.color.g) / len;
	l.index.color.b += (l.end.color.b - l.start.color.b) / len;
	return (l.index.color);
}

int	bld_clr(t_n_l line, t_line_pts line_pts, t_image *img, char tb)
{
	unsigned int	bg[2];
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			alpha;
	(void)img;

	// bg[0] = *((unsigned int *)(line.ost + img->px_ptr));
	bg[0] = 0x000000;
	bg[1] = rgbtoi(line_pts.start.color);
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
