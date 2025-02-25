/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:52:02 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/25 17:58:39 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	my_abs(t_line_pts line_pts, char xy)
{
	int res;
	
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
	int	tempo;

	tempo = line_pts.start.x;
	line_pts.start.x = line_pts.end.x;
	line_pts.end.x = tempo;
	tempo = line_pts.start.y;
	line_pts.start.y = line_pts.end.y;
	line_pts.end.y = tempo;
	return (line_pts);
}

int	calc_offset(t_image *img, t_n_l line, char hb)
{
	if (hb != 't')
		return ((img->line_len * line.iy) + (line.ix * (img->bits_pp / 8)));
	return ((img->line_len * line.iy) + ((line.ix + 1) * (img->bits_pp / 8)));
}
