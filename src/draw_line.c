/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:07:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/24 17:04:16 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_hori_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	unsigned int	color;
	line.dx = line_pts.end.sx - line_pts.start.sx;
	line.dy = line_pts.end.sy - line_pts.start.sy;
	if (line.dx != 0)
		line.m = line.dy / line.dx;
	else
		line.m = 1;
	line.i = 0;
	while (line.i++ < (int)line.dx)
	{
		line.x = line_pts.start.sx + line.i;
		line.y = line_pts.start.sy + (line.i * line.m);
		line.ix = (int)line.x;
		line.iy = (int)floor(line.y);
		line.dist = (line.y - line.iy);
		line.ost = calc_offset(img, line_pts, 't');
		line.osb = calc_offset(img, line_pts, 'b');
		color = bld_clr(line, line_pts, img, 't');
		// my_px_p(img, line_pts.index.sx, line_pts.index.sy, color);
		my_px_p(img, line.ix, line.iy, color);
		// printf("l.start sx: %d l.start sy:%d\n", line_pts.start.sx, line_pts.start.sy);
		// printf("l.end sx: %d l.end sy:%d\n\n", line_pts.end.sx, line_pts.end.sy);
		color = bld_clr(line, line_pts, img, 'b');
		// my_px_p(img, line_pts.index.sx, line_pts.index.sy + 1, color);
		my_px_p(img, line.ix, line.iy + 1, color);
	}
	// my_px_p(img, line_pts.index.sx, line_pts.index.sy,
	// 	rgbtoi(line_pts.end.color));
}

void	draw_vert_line(t_n_l line, t_line_pts line_pts, t_image *img)
{
	// unsigned int	color;
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
		line_pts.index.color = interpol_color(line_pts);
		my_px_p(img, line.ix, line.iy, bld_clr(line, line_pts, img, 't'));
		line_pts.index.color = interpol_color(line_pts);
		my_px_p(img, line.ix + 1, line.iy, bld_clr(line, line_pts, img, 't'));
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
		// printf("l.start sx: %d, start sy: %d\n", line_pts.start.sx, line_pts.start.sy);
		// printf("l.end sx: %d, end sy: %d\n", line_pts.end.sx, line_pts.end.sy);
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
	// t_rgba		temp_color;
	// int	tempo;

	l.start = start;
	l.end = end;
	printf("Z: %f\n", l.end.z);
	// if ((l.end.sx - l.start.sx) < 0)
	// {
	// 	temp_color = l.start.color;
	// 	swap((void **)&l.start, (void **)&l.end);
	// 	l.start.color = l.end.color;
	// 	l.end.color = temp_color;
	// }
	// if (l.end.y < l.start.y)
	// {
	// 	tempo = l.end.y;
	// 	l.end.y = l.start.y;
	// 	l.start.y = tempo;
	// }
	l.index = l.start;
	// l.d.sx = l.end.sx - l.start.sx;
	// l.d.sy = l.end.sy - l.start.sy;
	wuline(l, img);
}
