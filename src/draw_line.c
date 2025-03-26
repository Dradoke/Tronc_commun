/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:07:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/26 13:41:29 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_hori_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	line.dx = line_pts.end.sx - line_pts.start.sx;
	line.dy = line_pts.end.sy - line_pts.start.sy;
	if (line.dx != 0)
		line.m = line.dy / line.dx;
	else
		line.m = 1;
	line.i = 0;
	my_px_p(img, line_pts.index.sx, line_pts.index.sy,
		rgbtoi(line_pts.end.color));
	while (line.i++ < (int)line.dx)
	{
		line.x = line_pts.start.sx + line.i;
		line.y = line_pts.start.sy + (line.i * line.m);
		line.ix = (int)line.x;
		line.iy = (int)floor(line.y);
		line.dist = (line.y - line.iy);
		line.ost = calc_offset(img, line_pts, 't');
		line.osb = calc_offset(img, line_pts, 'b');
		line_pts.index.sx = line.ix;
		line_pts.index.color = interpol_color_h(line_pts);
		my_px_p(img, line.ix, line.iy, bld_clr(line, line_pts, 't'));
		line_pts.index.color = interpol_color_h(line_pts);
		my_px_p(img, line.ix, line.iy + 1, bld_clr(line, line_pts, 'b'));
	}
}

void	draw_vert_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	line.dx = line_pts.end.sx - line_pts.start.sx;
	line.dy = line_pts.end.sy - line_pts.start.sy;
	if (line.dy != 0)
		line.m = line.dx / line.dy;
	else
		line.m = 1;
	line.i = 0;
	while (line.i++ < line.dy)
	{
		line.x = line_pts.start.sx + (line.i * line.m);
		line.y = line_pts.start.sy + line.i;
		line.ix = (int)line.x;
		line.iy = (int)floor(line.y);
		line.dist = (line.x - line.ix);
		line.ost = calc_offset(img, line_pts, 't');
		line.osb = calc_offset(img, line_pts, 'b');
		line_pts.index.sy = line.iy;
		line_pts.index.color = interpol_color_v(line_pts);
		my_px_p(img, line.ix, line.iy, bld_clr(line, line_pts, 't'));
		line_pts.index.color = interpol_color_v(line_pts);
		my_px_p(img, line.ix + 1, line.iy, bld_clr(line, line_pts, 'b'));
	}
	my_px_p(img, line_pts.start.sx, line_pts.start.sy,
		rgbtoi(line_pts.start.color));
}

void	wuline(t_line_pts line_pts, t_image *img)
{
	t_n_l	line;

	if (my_abs(line_pts, 'y') < my_abs(line_pts, 'x'))
	{
		if (line_pts.end.sx < line_pts.start.sx)
			line_pts = change_points(line_pts);
		draw_hori_line(line, line_pts, img);
	}
	else
	{
		if (line_pts.end.sy < line_pts.start.sy)
			line_pts = change_points(line_pts);
		draw_vert_line(line, line_pts, img);
	}
}

void	draw_grid(t_image *img, t_map grid)
{
	int		x;
	int		y;

	y = 0;
	while (y < grid.height)
	{
		x = 0;
		while (x < grid.width)
		{
			if (x < grid.width - 1)
				draw_line(img, grid.tab[x][y], grid.tab[x + 1][y]);
			if (y < grid.height - 1)
				draw_line(img, grid.tab[x][y], grid.tab[x][y + 1]);
			x++;
		}
		y++;
	}
}

void	draw_line(t_image *img, t_points start, t_points end)
{
	t_line_pts	l;

	l.start = start;
	l.end = end;
	l.index = l.start;
	wuline(l, img);
}
