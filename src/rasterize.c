/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:06:10 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/11 15:49:39 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_matrix(t_data *data, t_mat4 *m)
{
	t_pmath	c;

	c.cos_rx = cos(ft_degtorad(data->in.rot_x));
	c.sin_rx = sin(ft_degtorad(data->in.rot_x));
	c.cos_ry = cos(ft_degtorad(data->in.rot_y));
	c.sin_ry = sin(ft_degtorad(data->in.rot_y));
	c.cos_rz = cos(ft_degtorad(data->in.rot_z));
	c.sin_rz = sin(ft_degtorad(data->in.rot_z));
	m->m[0][0] = c.cos_ry * c.cos_rz;
	m->m[0][1] = -c.cos_ry * c.sin_rz;
	m->m[0][2] = c.sin_ry;
	m->m[1][0] = c.sin_rx * c.sin_ry * c.cos_rz + c.cos_rx * c.sin_rz;
	m->m[1][1] = -c.sin_rx * c.sin_ry * c.sin_rz + c.cos_rx * c.cos_rz;
	m->m[1][2] = -c.sin_rx * c.cos_ry;
	m->m[2][0] = -c.cos_rx * c.sin_ry * c.cos_rz + c.sin_rx * c.sin_rz;
	m->m[2][1] = c.cos_rx * c.sin_ry * c.sin_rz + c.sin_rx * c.cos_rz;
	m->m[2][2] = c.cos_rx * c.cos_ry;
	m->m[0][3] = 0;
	m->m[1][3] = 0;
	m->m[2][3] = 0;
	m->m[3][3] = 1.0f;
}

void	apply_mat4(t_points *p, t_mat4 *m)
{
	p->sx = p->x * m->m[0][0] + p->y * m->m[0][1] + p->z * m->m[0][2];
	p->sy = p->x * m->m[1][0] + p->y * m->m[1][1] + p->z * m->m[1][2];
}

t_tab	rasterize(t_data *data)
{
	int		y;
	int		x;

	init_matrix(data, &data->tab.mtrx);
	y = 0;
	while (y < data->tab.height)
	{
		x = 0;
		while (x < data->tab.width)
			apply_mat4(&data->tab.tab[x++][y], &data->tab.mtrx);
		y++;
	}
	return (data->tab);
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
