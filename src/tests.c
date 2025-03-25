/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:41:01 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:35:01 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	checktab(t_map tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < tab.height)
	{
		x = 0;
		while (x < tab.width)
		{
			printf("Point at (%d, %d):\tx=%f,\ty=%f,\tz=%f,\tcolor=%X,\tsx=%i,\tsy=%i\n",
				x, y, tab.tab[x][y].x, tab.tab[x][y].y,
				tab.tab[x][y].z, rgbtoi(tab.tab[x][y].color),
				tab.tab[x][y].sx, tab.tab[x][y].sy);
			x++;
		}
		y++;
	}
	printf("\n");
}

// void	move_img(t_data *data)
// {
// 	// if (data->img.img_ptr)
//     //     mlx_destroy_image(data->mlx, data->img.img_ptr);
// 	// if (data->img.img_ptr)
// 	// 	free(data->img.img_ptr);
// 	// data->img.img_ptr = NULL;
//     // Créer une nouvelle image
//     // data->img.img_ptr = mlx_new_image(data->mlx, data->win_width, data->win_height);
// 	printf("adresse de img: %p", &data->img.img_ptr);
//     // Dessiner la nouvelle image (remplie en noir par défaut)
// 	mlx_clear_window(data->mlx, data->win);
// 	// drawtabiso(&data->img, *data->map);
// 	draw_grid(data->img.img_ptr, *data->map);
//     mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
// }
