/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/06 10:09:29 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"
#include <X11/keysym.h>

#define SPACE 32

typedef struct	s_data {
	void	*img;
	int		img_height;
	int		img_width;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	int		win_width;
	int		win_height;
	int     key_pressed;
    long    press_time;
}				t_vars;

typedef struct s_timeval{
	long	sec;
	long	usec;
}				t_timeval;


int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	mlx_do_key_autorepeaton(vars->mlx);
	free(vars->mlx);
	exit(1);
	return(0);
}
int mouse_move(int x, int y)
{
    if (x >= 0 && x < 500 && y >= 0 && y < 500)
        printf("Mouse inside window: (%d, %d)\n", x, y);
    if (x < 0 && x > 500 && y < 0 && y > 500)
        printf("Mouse outside window\n");
    return (0);
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
long get_time_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		printf("end of window\n");
		close_window(vars);
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



int main(void)
{
	t_vars data = {0};
	char	*relative_path = "./test.xpm";
	
	data.win_height = 500;
	data.win_width = 500;
	data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Test");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	mlx_xpm_file_to_image(data.mlx, relative_path, &data.win_width, &data.win_height);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2,1L << 0, key_press, &data);
	mlx_hook(data.win, 3,1L << 1, key_release, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move, NULL);
	mlx_hook(data.win,17,1L << 17, close_window, &data);
	mlx_loop(data.mlx);	
	return (0);
}
