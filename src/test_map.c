/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:01:03 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <unistd.h>

void	init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->win_width = WIN_WIDTH;
	data->win_height = WIN_HEIGHT;
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "FdF1");
	if (!data->win)
	{
		free(data->mlx);
		return ;
	}
	data->img.img_ptr = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (!data->img.img_ptr)
		return (free(data->win), free(data->mlx));
	data->img.px_ptr = mlx_get_data_addr(data->img.img_ptr,
        &data->img.bits_pp, &data->img.line_len, &data->img.endian);
	data->img.mv_tab.ix = 0;
	data ->img.mv_tab.iy = 0;
}

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
	data.map = &map;
    ft_printf("GRID TAB 1: %d\n", map.tab[0][0].sx);
	init(&data);
	drawtabiso(&data.img, map);
    ft_printf("OUAIS\n");
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
    return 0;
}
