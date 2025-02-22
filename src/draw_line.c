/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:07:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/22 14:10:44 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_horizontal_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	unsigned int	color;

	line.dx = line_pts.x1 - line_pts.x0;
	line.dy = line_pts.y1 - line_pts.y0;
	if (line.dx != 0)
		line.m = line.dy / line.dx;
	else
		line.m = 1;
	line.i = 0;
	while (line.i++ < (int)line.dx)
	{
		line.x = line_pts.x0 + line.i;
		line.y = line_pts.y0 + (line.i * line.m);
		line.ix = (int)line.x;
		line.iy = (int)floor(line.y);
		line.dist = (line.y - line.iy);
		line.ost = calc_offset(img, line, 't');
		line.osb = calc_offset(img, line, 'b');
		color = bld_clr(line, line_pts, img, 't');
		my_px_p(img, line.ix, line.iy, color);
		color = bld_clr(line, line_pts, img, 'b');
		my_px_p(img, line.ix, line.iy + 1, color);
	}
	my_px_p(img, line_pts.x0, line_pts.y0, line_pts.color);
}

void	draw_vertical_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	unsigned int	color;

	line.dx = line_pts.x1 - line_pts.x0;
	line.dy = line_pts.y1 - line_pts.y0;
	if (line.dy != 0)
		line.m = line.dx / line.dy;
	else
		line.m = 1;
	line.i = 0;
	while (line.i++ < (int)line.dy)
	{
		line.x = line_pts.x0 + (line.i * line.m);
		line.y = line_pts.y0 + line.i;
		line.ix = (int)line.x;
		line.iy = (int)floor(line.y);
		line.dist = (line.x - line.ix);
		line.ost = calc_offset(img, line, 't');
		line.osb = calc_offset(img, line, 'b');
		color = bld_clr(line, line_pts, img, 't');
		my_px_p(img, line.ix, line.iy, color);
		color = bld_clr(line, line_pts, img, 'b');
		my_px_p(img, line.ix + 1, line.iy, color);
	}
	my_px_p(img, line_pts.x0, line_pts.y0, line_pts.color);
}

void	make_line(t_line_pts line_pts, t_image *img)
{
	t_n_l	line;

	if (my_abs(line_pts.y1 - line_pts.y0) < my_abs(line_pts.x1 - line_pts.x0))
	{
		if (line_pts.x1 < line_pts.x0)
			line_pts = change_points(line_pts);
		draw_horizontal_line(line, line_pts, img);
	}
	else
	{
		if (line_pts.y1 < line_pts.y0)
			line_pts = change_points(line_pts);
		draw_vertical_line(line, line_pts, img);
	}
}
