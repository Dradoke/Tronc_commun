/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:07:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/20 19:46:14 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double pourcentage_difference(double A, double B) {
    if (A == 0) {
        return 0;  // Éviter la division par zéro
    }
    return ((B - A) / A);
}

void draw_line(t_line line, t_image *image)
{
	float dx;
	float dy;
	float m;
	float x;
	float y;
	double dist;
	int ix;
	int iy;
	int offset;
	int	i;
	
	i = 0;
	dx = line.x1 - line.x0;
	dy = line.y1 - line.y0;
	if (dx != 0)
		m = dy/dx;
	else
		m = 1;
	while(i++ < (int)dx)
	{
		x = line.x0 + i;
		y = line.y0 + (i * m);
		ix = (int)x;
		iy = (int)floor(y);
		dist = (y - iy);
		printf("iy = %f   iy+1 = %f\n", 1 - dist, dist);
		offset = (image->line_len * iy) + (ix * (image->bits_per_pixel / 8));
		my_pixel_put(image, ix, iy, blend_color(*((unsigned int *)(offset + image->image_pixel_ptr)), line.color, 1 - dist));
		my_pixel_put(image, ix, iy+1, blend_color(*((unsigned int *)(offset + image->image_pixel_ptr)), line.color, dist));
	}
	my_pixel_put(image, line.x0, line.y0, line.color);
	my_pixel_put(image, line.x1, line.y1, line.color);
}


