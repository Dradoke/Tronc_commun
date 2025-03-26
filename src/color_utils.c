/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:43:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/26 13:38:47 by ngaudoui         ###   ########.fr       */
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

// void	gradient(t_line_pts *l, t_n_l nl)
// {
// 	int	steps;
// 	int	i;
// 	float	t;

// 	if (c_abs(nl.dx) > c_abs(nl.dy))
// 		steps = c_abs(nl.dx);
// 	else
// 		steps = c_abs(nl.dy);
// 	while (i <= steps)
// 	{
// 		t = (float)i / (float)steps;
		
// 	}
// }

t_rgba	interpol_color_v(t_line_pts line_pts)
{
	t_rgba	interpolated_color;
	float	t;

	if (line_pts.end.sy - line_pts.start.sy == 0)
		t = 0;
	else
		t = (float)(line_pts.index.sy - line_pts.start.sy)
			/ (float)(line_pts.end.sy - line_pts.start.sy);
	interpolated_color.r = (unsigned char)(line_pts.start.color.r
			+ t * (line_pts.end.color.r - line_pts.start.color.r));
	interpolated_color.g = (unsigned char)(line_pts.start.color.g
			+ t * (line_pts.end.color.g - line_pts.start.color.g));
	interpolated_color.b = (unsigned char)(line_pts.start.color.b
			+ t * (line_pts.end.color.b - line_pts.start.color.b));
	return (interpolated_color);
}

t_rgba	interpol_color_h(t_line_pts line_pts)
{
	t_rgba	interpolated_color;
	float	t;

	if (line_pts.end.sx - line_pts.start.sx == 0)
		t = 0;
	else
		t = (float)(line_pts.index.sx - line_pts.start.sx)
			/ (float)(line_pts.end.sx - line_pts.start.sx);
	interpolated_color.r = (unsigned char)(line_pts.start.color.r
			+ t * (line_pts.end.color.r - line_pts.start.color.r));
	interpolated_color.g = (unsigned char)(line_pts.start.color.g
			+ t * (line_pts.end.color.g - line_pts.start.color.g));
	interpolated_color.b = (unsigned char)(line_pts.start.color.b
			+ t * (line_pts.end.color.b - line_pts.start.color.b));
	return (interpolated_color);
}

int	bld_clr(t_n_l line, t_line_pts line_pts, char tb)
{
	unsigned int	bg[2];
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			alpha;

	bg[0] = 0x000000;
	bg[1] = rgbtoi(line_pts.index.color);
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
