/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:54 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/19 16:17:07 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "bit_shifting.h"
# include "color_utils.h"
# include <sys/time.h>
#include <math.h>

typedef struct	s_line {
	int x0;
	int y0;
	int x1;
	int y1;
	int color;
}				t_line;

typedef struct	s_image {
	void	*image_ptr;
	char	*image_pixel_ptr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_image;

void draw_line(t_line line, t_image *image);
void my_pixel_put(t_image *image, int x, int y, int color);