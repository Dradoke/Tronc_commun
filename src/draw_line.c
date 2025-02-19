/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:07:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/19 16:24:55 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void draw_line(t_line line, t_image *image)
{
	float dx;
	float dy;
	float m;
	float x;
	float y;
	float dist;
	int ix;
	int iy;
	int	i;

	dx = line.x1 - line.x0;
	dy = line.y1 - line.y0;
	if (dx != 0)
		m = dy/dx;
	else
		m = 1;
	while(i < (int)dx + 1)
	{
		x = line.x0 + i;
		y = line.y0 + (i * m);
		ix = (int)x;
		iy = (int)round(y);
		printf("iy = %i", iy);
		dist = y - iy;
		// my_pixel_put(image, ix, iy, ((int)(1 - dist) << 24 | line.color));
		// my_pixel_put(image, ix, iy, ((int)dist << 24 | line.color));

		my_pixel_put(image, ix, iy, line.color);
		my_pixel_put(image, ix, iy, line.color);
		i++;
	}
	my_pixel_put(image, line.x0, line.y0, line.color);
	my_pixel_put(image, line.x1, line.y1, line.color);
}
