/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:52:02 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/26 13:43:41 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	my_abs(t_line_pts line_pts, char xy)
{
	int	res;

	if (xy == 'y')
	{
		res = line_pts.end.y - line_pts.start.y;
		if (res < 0)
			return (res *= -1);
		return (res);
	}
	if (xy == 'x')
	{
		res = line_pts.end.x - line_pts.start.x;
		if (res < 0)
			return (res *= -1);
		return (res);
	}
	return (0);
}

t_line_pts	change_points(t_line_pts line_pts)
{
	int		tempo;
	t_rgba	color;

	tempo = line_pts.start.sx;
	line_pts.start.sx = line_pts.end.sx;
	line_pts.end.sx = tempo;
	tempo = line_pts.start.sy;
	line_pts.start.sy = line_pts.end.sy;
	line_pts.end.sy = tempo;
	color = line_pts.start.color;
	line_pts.start.color = line_pts.end.color;
	line_pts.end.color = color;
	return (line_pts);
}

int	calc_offset(t_image *img, t_line_pts line, char hb)
{
	if (hb != 't')
		return ((img->line_len * line.index.sy) + (line.index.sx * (img->bits_pp / 8)));
	return ((img->line_len * line.index.sy) + ((line.index.sx + 1) * (img->bits_pp / 8)));
}

void	my_px_p(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_pp / 8));
	*((unsigned int *)(offset + img->px_ptr)) = color;
}
