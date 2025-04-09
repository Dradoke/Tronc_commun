/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/09 12:31:59 by ngaudoui         ###   ########.fr       */
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

char	init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF1");
	if (!data->win)
		return (free(data->mlx), 0);
	init_img(data);
	return (1);
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
