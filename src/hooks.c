/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:18:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/04 13:24:26 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	remove_xpm_image(t_data *data)
{
	if (data->img.xpm_img)
	{
		mlx_clear_window(data->mlx, data->win);
		while (data->mlx->do_flush && data->easter_egg)
			;
		data->easter_egg = false;
		data->mlx->do_flush = 0;
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0,
			0);
	}
}

int	key_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		return (close_window(data), exit(0), 1);
	if (data->img.xpm_img && data->easter_egg == false)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.xpm_img, 0,
			0);
		data->easter_egg = true;
	}
	else if (data->img.xpm_img && data->easter_egg == true)
		remove_xpm_image(data);
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	rotate_hook(key, data);
	translate_hook(key, data);
	height_hook(key, data);
	zoom_hook(key, data);
	init_img(data);
	drawtabiso(data);
	return (1);
}

int	rotate_hook(int key, t_data *data)
{
	if (key == XK_s && data->in.rot_x > -90)
		data->in.rot_x -= 1;
	if (key == XK_a)
		data->in.rot_z -= 1;
	if (key == XK_w && data->in.rot_x < 90)
		data->in.rot_x += 1;
	if (key == XK_d)
		data->in.rot_z += 1;
	if (key == XK_q)
		data->in.rot_y -= 1;
	if (key == XK_e)
		data->in.rot_y += 1;
	return (1);
}

int	translate_hook(int key, t_data *data)
{
	if (key == XK_Up)
		data->in.pos_y -= 10;
	if (key == XK_Down)
		data->in.pos_y += 10;
	if (key == XK_Right)
		data->in.pos_x += 10;
	if (key == XK_Left)
		data->in.pos_x -= 10;
	return (1);
}

int	height_hook(int key, t_data *data)
{
	if (key == XK_r)
		data->in.h_factr += 1;
	if (key == XK_f)
		data->in.h_factr -= 1;
	return (1);
}

int	zoom_hook(int key, t_data *data)
{
	if (key == XK_t)
	{
		data->in.zoom_bool = 0;
		data->in.zoom += 0.01;
	}
	if (key == XK_g)
	{
		data->in.zoom_bool = 0;
		data->in.zoom -= 0.01;
	}
	if (key == XK_z)
	{
		if (data->in.zoom_bool == 1)
			data->in.zoom_bool = 0;
		if (data->in.zoom_bool == 0)
			data->in.zoom_bool = 1;
	}
	return (1);
}
