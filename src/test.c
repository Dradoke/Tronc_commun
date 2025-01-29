/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/01/29 13:41:23 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"

#define ESC 65307
#define A 97

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_timeval {
	long	sec;
	long	usec;
}				t_timeval;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y*data->line_length + x * (data->bits_per_pixel / 8));
    (*(unsigned int*)dst = color);
}
int	handle_unmap_event(void *param)
{
	(void)param;
	printf("La fenêtre a été minimisée ou cachée !\n");
	return (0);
}

int	handle_visibility_event(int visibility, void *param)
{
	(void)param;
	if (visibility == 0)
		printf("The window has been hide !\n");
	if (visibility == 1)
		printf("The window is half visible !\n");
	if (visibility == 2)
		printf("Th window is visible !\n");
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		printf("end of window\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (keycode == 32)
		printf("Space");
	return (0);
}
long long	time_between(t_timeval start, t_timeval end)
{
	long long	start_ms;
	long long	end_ms;
	
	start_ms = start.sec * 1000LL + start.usec / 1000;
	end_ms = end.sec * 1000LL + end.usec / 1000;
	return (end_ms - start_ms);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return(0);
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
	t_timeval timestart;
	t_timeval timeend;

	
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Test");
	mlx_hook(mlx_win, 2,1L << 0, key_press, NULL);
	mlx_hook(mlx_win,17,1L<<17, close_window, NULL);
	mlx_loop(mlx);	
}
