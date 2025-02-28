/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:07:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/28 19:09:36 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_hori_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	unsigned int	color;

	line.dx = line_pts.end.x - line_pts.start.x;
	line.dy = line_pts.end.y - line_pts.start.y;
	if (line.dx != 0)
		line.m = line.dy / line.dx;
	else
		line.m = 1;
	line.i = 0;
	while (line.i++ < (int)line.dx)
	{
		line.x = line_pts.start.x + line.i;
		line.y = line_pts.start.y + (line.i * line.m);
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
	my_px_p(img, line_pts.start.x, line_pts.start.y, line_pts.start.color);
}

void	draw_vert_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	unsigned int	color;

	line.dx = line_pts.end.x - line_pts.start.x;
	line.dy = line_pts.end.y - line_pts.start.y;
	if (line.dy != 0)
		line.m = line.dx / line.dy;
	else
		line.m = 1;
	line.i = 0;
	while (line.i++ < (int)line.dy)
	{
		line.x = line_pts.start.x + (line.i * line.m);
		line.y = line_pts.start.y + line.i;
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
	my_px_p(img, line_pts.start.x, line_pts.start.y, line_pts.start.color);
}

void	make_line(t_line_pts line_pts, t_image *img)
{
	t_n_l	line;

	if (my_abs(line_pts, 'y') < my_abs(line_pts, 'x'))
	{
		if (line_pts.end.x < line_pts.start.x)
			line_pts = change_points(line_pts);
		draw_hori_line(line, line_pts, img);
	}
	else
	{
		if (line_pts.end.y < line_pts.start.y)
			line_pts = change_points(line_pts);
		draw_vert_line(line, line_pts, img);
	}
}
