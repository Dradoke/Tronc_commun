/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/11 15:33:22 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"
#include <X11/keysym.h>

#define WIN_LEN 800

typedef struct	s_image {
	void	*image_ptr;
	char	*image_pixel_ptr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_image;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_image	image;
	int     img_width;
    int     img_height;
}				t_vars;



int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->image.image_ptr);
	mlx_destroy_display(vars->mlx);
	mlx_do_key_autorepeaton(vars->mlx);
	free(vars->mlx);
	exit(1);
	return(0);
}
void my_pixel_put(t_image *image, int x, int y, int color)
{
	int offset;

	offset = (image->line_len * y) + (x * (image->bits_per_pixel / 8));
	*((unsigned int *)(offset + image->image_pixel_ptr)) = color;
}

void color_screen(t_vars *vars, char *file)
{
	if (vars->image.image_ptr)
		mlx_destroy_image(vars->mlx,vars->image.image_ptr);
	mlx_clear_window(vars->mlx, vars->win);
	vars->image.image_ptr = mlx_xpm_file_to_image(vars->mlx, file, &vars->img_width, &vars->img_height);
	if (vars->image.image_ptr)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.image_ptr, 0, 0);
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
		color_screen(vars, "test_mlx/open.xpm");
	}
	else if (keysym == XK_g)
	{
		color_screen(vars, "test_mlx/open24.xpm");
	}
	else if (keysym == XK_b)
	{
		color_screen(vars, "test_mlx/open30.xpm");
	}
	return (0);
}


int main(void)
{
	t_vars data;
	
	data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIN_LEN, WIN_LEN, "Test");

	
	data.image.image_ptr = mlx_new_image(data.mlx, WIN_LEN, WIN_LEN);
	data.image.image_pixel_ptr = mlx_get_data_addr(data.image.image_ptr, &data.image.bits_per_pixel, &data.image.line_len, &data.image.endian);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win,17,1L << 17, close_window, &data);
	mlx_loop(data.mlx);	
	return (0);
}
