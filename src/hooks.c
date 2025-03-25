/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:18:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 12:36:25 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int mouse_hook(int button, int x, int y, t_data *app)
{
	(void)x;
	(void)y;
    if (button == 1)  // Left mouse button
    {
        if (x >= app->win_width - 10 && y >= app->win_height - 10) // Bottom-right corner
        {
            app->resizing = 1; // Start resizing
        }
    }
    return 0;
}

