/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:49:40 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:00:33 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "fdf.h"
typedef struct s_rgba
{
	float	r;
	float	g;
	float	b;
}				t_rgba;

typedef struct s_points
{
	float		x;
	float		y;
	float		z;
	t_rgba	color;
	int		sx;
	int		sy;
}				t_points;

typedef struct s_index
{
	int	ix;
	int	iy;
}				t_index;

typedef struct s_map
{
	t_points	**tab;
	char		**lines;
	int			width;
	int			height;
	double		scale;
}				t_map;

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

typedef struct s_tablim
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;
}				t_tablim;

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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_map	*map;
	int      win_width;
    int      win_height;
}				t_data;
#endif
