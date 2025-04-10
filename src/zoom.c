/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:34:33 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/10 14:33:36 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	getscale(t_data *data)
{
	while (data->tab.lim.xmax * data->in.zoom < (WIN_WIDTH / 2) - 20
		&& data->tab.lim.ymax * data->in.zoom < (WIN_HEIGHT / 2) - 20
		&& data->tab.lim.xmin * data->in.zoom > (-WIN_WIDTH / 2) + 20
		&& data->tab.lim.ymin * data->in.zoom > (-WIN_HEIGHT / 2) + 20)
		data->in.zoom += 1.0 / (data->tab.lim.xmax * data->tab.lim.ymax);
}

void	autozoom(t_data *data)
{
	int		x;
	int		y;

	data->in.zoom = 0;
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			getscale(data);
			data->tab.tab[x][y].sx *= data->in.zoom;
			data->tab.tab[x][y].sy *= data->in.zoom;
			x++;
		}
		y++;
	}
}

void	manualzoom(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].sx *= data->in.zoom;
			data->tab.tab[x][y].sy *= data->in.zoom;
			x++;
		}
		y++;
	}
}
