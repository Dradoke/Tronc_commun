/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/01/31 14:18:08 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"

#define ESC 65307
#define SPACE 32

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
	int     key_pressed;
    long    press_time;
}				t_vars;

typedef struct s_timeval{
	long	sec;
	long	usec;
}				t_timeval;


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
long get_time_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		printf("end of window\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == SPACE)
	{
		if (vars->key_pressed == 0)
		{
			printf("key_pressed : %i\n", vars->key_pressed);
			mlx_do_key_autorepeatoff(vars->mlx);
			vars->key_pressed = 1;
			vars->press_time = get_time_ms();
		}
	}
	if (keycode ==48)
		vars->win = mlx_new_window(vars->mlx, 500, 500, "Test");
	return (0);
}
int mouse_enter_window(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	printf("The mouse has enter the Window");
	return (0);
}

int key_release(int keycode, t_vars *vars)
{
	long	duration;
	if (keycode == SPACE && vars->key_pressed == 1)
	{
			duration = get_time_ms() - vars->press_time;
			if (duration > 1500 && duration < 2500)
				printf("duration : %li\n", duration);
			vars->key_pressed = 0;
	}
	// else if (keycode != 32 && vars->key_pressed == 1)
	// {
		
	// }
	return (0);
}
// int loop_time_hook(t_vars *vars)
// {
// 	long current_time;
// 	if (vars->key_pressed)
// 		current_time = get_time_ms();
// }

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return(0);
}

int main(void)
{
	t_vars data = {0};

	// data.key_pressed = 0;
	// data.press_time = 0;
	data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 500, 500, "Test");
	mlx_hook(data.win, 2,1L << 0, key_press, &data);
	mlx_hook(data.win, 3,1L << 1, key_release, &data);
	mlx_hook(data.win, 7,1L << 14, mouse_enter_window, &data);
	mlx_hook(data.win,17,1L<<17, close_window, &data);
	mlx_loop(data.mlx);	
}
