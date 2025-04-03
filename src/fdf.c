/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/03 17:29:20 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <unistd.h>

char	init_img(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img_ptr)
		return (free(data->mlx), free(data->win), 0);
	data->img.px_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_pp, &data->img.line_len, &data->img.endian);
	return (1);
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->easter_egg = false;
	data->win_width = WIN_WIDTH;
	data->win_height = WIN_HEIGHT;
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"FdF1");
	if (!data->win)
	{
		free(data->mlx);
		return ;
	}
	data->img.img_ptr = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	if (!data->img.img_ptr)
		return (free(data->win), free(data->mlx));
	data->img.px_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_pp,
			&data->img.line_len, &data->img.endian);
	data->img.xpm_height = 0;
	data->img.xpm_width = 0;
	data->img.xpm_img = mlx_xpm_file_to_image(data->mlx,
			"./assets/paul.xpm", &data->img.xpm_width,
			&data->img.xpm_height);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (ft_printf(ERROR_ARG, argc), 1);
	if (!build_tab(argv[1], &data.tab))
		return (ft_printf(ERROR_MAP, argv[1]), 1);
	init(&data);
	data.in = (t_input){45, 30, -35, 0, 1, 100, 0, 0};
	drawtabiso(&data);
	mlx_hook(data.win, 2, 1L << 0, key_handler, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
