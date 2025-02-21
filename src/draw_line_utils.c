/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:52:02 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/21 19:09:05 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int my_abs(int a)
{
	if (a < 0)
		return(a*=-1);
	return(a);
}
t_line_pts change_points(t_line_pts line_pts)
{
	int tempo;

	tempo = line_pts.x0;
	line_pts.x0 = line_pts.x1;
	line_pts.x1 = tempo;
	tempo = line_pts.y0;
	line_pts.y0 = line_pts.y1;
	line_pts.y1 = tempo;
	return(line_pts);
}