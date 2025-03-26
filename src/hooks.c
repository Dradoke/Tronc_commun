/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:18:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/26 16:20:43 by ngaudoui         ###   ########.fr       */
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

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		close_window(data);
		exit(0);
	}
	if (keysym == XK_Up && !data->easter_egg)
	{
		data->easter_egg = 1;
		if (data->img.xpm_img)
			mlx_put_image_to_window(data->mlx, data->win, data->img.xpm_img, 0,
				0);
	}
	if (keysym == XK_Down && data->easter_egg)
		remove_xpm_image(data);
	return (0);
}
