/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/25 18:07:13 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"
#include <X11/keysym.h>

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	mlx_do_key_autorepeaton(vars->mlx);
	free(vars->mlx);
	exit(1);
	return (0);
}

void	my_px_p(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_pp / 8));
	*((unsigned int *)(offset + img->px_ptr)) = color;
}

void	color_screen(t_vars *vars, int color)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			my_px_p(&vars->img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

int	key_press(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		printf("end of window\n");
		close_window(vars);
		exit(0);
	}
	if (keysym == XK_r)
	{
		color_screen(vars, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(vars, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(vars, 0xff);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	return (0);
}
void draw_text(t_vars *data)
{
    mlx_string_put(data->mlx, data->win, (WIN_WIDTH /2 - strlen("Bonjo")* 2.75), WIN_HEIGHT /2, 0x0000FF00, "Bonjo");
}

int	main(int argc, char **argv)
{
	t_vars		data;
	t_line_pts	line;

	if (argc < 5)
	    return (1);
	line.start.color = 0x00FF0000;
	line.end.color = 0x00FF0000;
	line.start.x = atoi(argv[1]);
	line.start.y = atoi(argv[2]);
	line.end.x = atoi(argv[3]);
	line.end.y = atoi(argv[4]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Test");
	data.img.img_ptr = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.px_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_pp,
			&data.img.line_len, &data.img.endian);
	// mlx_loop_hook(data.mlx, (void *)draw_text, &data);
	make_line(line, &data.img);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 1L << 17, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
