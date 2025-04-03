/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:16:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/03 17:35:51 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	adjust_coord(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].sx += ((WIN_WIDTH - 1) / 2);
			data->tab.tab[x][y].sy += ((WIN_HEIGHT - 1) / 2);
			data->tab.tab[x][y].sx += data->in.pos_x;
			data->tab.tab[x][y].sy += data->in.pos_y;
			x++;
		}
		y++;
	}
	return (1);
}

t_tab	centermap(t_data *data)
{
	int		yoffset;
	int		xoffset;
	int		x;
	int		y;

	yoffset = (c_abs(data->tab.lim.ymin) - c_abs(data->tab.lim.ymax)) / 2;
	xoffset = (c_abs(data->tab.lim.xmin) - c_abs(data->tab.lim.xmax)) / 2;
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].sy += yoffset;
			data->tab.tab[x][y].sx += xoffset;
			x++;
		}
		y++;
	}
	return (data->tab);
}

void	enlargetab(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].x *= 100;
			data->tab.tab[x][y].y *= 100;
			if (data->in.h_factr != 0)
				data->tab.tab[x][y].z *= data->in.h_factr;
			x++;
		}
		y++;
	}
}

float	ft_degtorad(float deg)
{
	float		pi;
	float		rad;

	pi = 3.14159265358979323846f;
	rad = deg * (pi / 180.0f);
	return (rad);
}
