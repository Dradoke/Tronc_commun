/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:06:10 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/03 18:32:29 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


t_tab	rasterize(t_data *data)
{
	int		y;
	int		x;
	t_points	*tp;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			tp = &data->tab.tab[x][y];
			tp->sx = (tp->x * cos(ft_degtorad(data->in.rot_z)) + (tp->y * sin(ft_degtorad(data->in.rot_x)) + tp->z * cos(ft_degtorad(data->in.rot_x))) * sin(ft_degtorad(data->in.rot_z))) * cos(ft_degtorad(data->in.rot_y)) - (tp->y * cos(ft_degtorad(data->in.rot_x)) - tp->z * sin(ft_degtorad(data->in.rot_x))) * sin(ft_degtorad(data->in.rot_y));
			tp->sy = (tp->x * cos(ft_degtorad(data->in.rot_z)) + (tp->y * sin(ft_degtorad(data->in.rot_x)) + tp->z * cos(ft_degtorad(data->in.rot_x))) * sin(ft_degtorad(data->in.rot_z))) * sin(ft_degtorad(data->in.rot_y)) + (tp->y * cos(ft_degtorad(data->in.rot_x)) - tp->z * sin(ft_degtorad(data->in.rot_x))) * cos(ft_degtorad(data->in.rot_y));
			x++;
		}
		y++;
	}
	return (data->tab);
}

void	getlim(t_tab *tab)
{
	int			x;
	int			y;

	tab->lim = (t_tablim){0};
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			if (tab->tab[x][y].sx <= tab->lim.xmin)
				tab->lim.xmin = tab->tab[x][y].sx;
			if (tab->tab[x][y].sx >= tab->lim.xmax)
				tab->lim.xmax = tab->tab[x][y].sx;
			if (tab->tab[x][y].sy <= tab->lim.ymin)
				tab->lim.ymin = tab->tab[x][y].sy;
			if (tab->tab[x][y].sy >= tab->lim.ymax)
				tab->lim.ymax = tab->tab[x][y].sy;
			x++;
		}
		y++;
	}
}

void	restoretab(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
		{
			data->tab.tab[x][y].x *= 0.01;
			data->tab.tab[x][y].y *= 0.01;
			if (data->in.h_factr != 0)
				data->tab.tab[x][y].z /= data->in.h_factr;
			x++;
		}
		y++;
	}
}

void	drawtabiso(t_data *data)
{
	enlargetab(data);
	rasterize(data);
	getlim(&data->tab);
	centermap(data);
	if (data->in.zoom_bool == 1)
		autozoom(data);
	if (data->in.zoom_bool == 0)
		manualzoom(data);
	adjust_coord(data);
	draw_grid(data);
	restoretab(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}

int	c_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}
