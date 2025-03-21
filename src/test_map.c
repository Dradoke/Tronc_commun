/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/21 18:03:40 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <unistd.h>

void	init(t_data *data)
{
	(*data).mlx = mlx_init();
	if (!(*data).mlx)
		return ;
	(*data).win = mlx_new_window((*data).mlx, WIN_WIDTH, WIN_HEIGHT, "FdF1");
	if (!(*data).win)
		return ;
	(*data).mlx = (*data).mlx;
	(*data).win = (*data).win;
	(*data).img.img_ptr = mlx_new_image((*data).mlx, WIN_WIDTH, WIN_HEIGHT);
	(*data).img.px_ptr = mlx_get_data_addr((*data).img.img_ptr,
        &(*data).img.bits_pp,&(*data).img.line_len, &(*data).img.endian);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("end of window\n");
		close_window(data);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_do_key_autorepeaton(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}

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

// Fonction principale
int main(int argc, char **argv)
{
    t_data		data;
    t_map map;
    
    if (argc != 2)
    {
        printf("Usage: %s <fichier_map.fdf>\n", argv[0]);
        return 1;
    }
    map = build_map(argv[1]);
    ft_printf("GRID TAB 1: %d\n", map.tab[0][0].sx);
    // checktab(map);
    // Libération de la mémoire
	init(&data);
	drawtabiso(&data.img, map);
    ft_printf("OUAIS\n");
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
    // free_map(&map);
    return 0;
}
