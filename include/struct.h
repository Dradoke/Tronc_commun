/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:49:40 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/10 14:44:02 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "fdf.h"
# include <stdbool.h>

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
}				t_rgb;

typedef struct s_points
{
	float		x;
	float		y;
	float		z;
	t_rgb		color;
	float		sx;
	float		sy;
}				t_points;

typedef struct s_index
{
	int	ix;
	int	iy;
}				t_index;

typedef struct s_tablim
{
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
}				t_tablim;

typedef struct s_mat4
{
	float		m[4][4];
}				t_mat4;

typedef struct s_tab
{
	t_points	**tab;
	char		**lines;
	int			width;
	int			height;
	t_tablim	lim;
	t_mat4		mtrx;
}				t_tab;

typedef struct s_line_pts
{
	t_points	start;
	t_points	end;
	t_points	index;
	t_points	d;
}				t_line_pts;

typedef struct s_image
{
	void	*img_ptr;
	char	*px_ptr;
	int		bits_pp;
	int		line_len;
	int		endian;
	t_index	mv_tab;
}				t_image;

typedef struct s_new_line
{
	float	dx;
	float	dy;
	float	m;
	float	x;
	float	y;
	double	dist;
	int		ix;
	int		iy;
	int		i;
	int		ost;
	int		osb;
}				t_n_l;

typedef struct s_input
{
	float		rot_x;
	float		rot_y;
	float		rot_z;
	float		zoom;
	int			zoom_bool;
	float		h_factr;
	int			pos_x;
	int			pos_y;
}				t_input;

typedef struct s_data
{
	t_xvar	*mlx;
	void	*win;
	t_image	img;
	t_tab	tab;
	int		win_width;
	int		win_height;
	t_input	in;
}				t_data;

typedef struct s_pmath
{
	float		cos_rx;
	float		sin_rx;
	float		cos_ry;
	float		sin_ry;
	float		cos_rz;
	float		sin_rz;
}				t_pmath;
#endif
