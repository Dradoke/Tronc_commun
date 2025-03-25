/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:18:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:35:05 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("end of window\n");
		close_window(data);
		exit(0);
	}
	// if (keysym == XK_Up)
	// {
	// 	data->img.mv_tab.iy += 10;
	// 	move_img(data);
	// }
	return (0);
}
