/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:54 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/14 16:26:15 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx_int.h"
#include "../minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include "bit_shifting.h"
#include <sys/time.h>
#include <math.h>


#define WIN_WIDTH 800
#define WIN_HEIGHT 800

typedef struct	s_points {
	int x;
	int y;
	int z;
	int color;
}				t_points;

typedef struct s_index {
	int ix;
	int iy;
}				t_index;

typedef struct	s_map {
	t_points **tab;
	char **lines;
	int width;
	int height;
}				t_map;

typedef struct	s_line_pts {
	t_points start;
	t_points end;
}				t_line_pts;

typedef struct s_image
{
	void	*img_ptr;
	char	*px_ptr;
	int		bits_pp;
	int		line_len;
	int		endian;
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_image	img;
}				t_vars;

int			bld_clr(t_n_l line, t_line_pts line_pts, t_image *img, char tb);
void		my_px_p(t_image *img, int x, int y, int color);
/*-----MAKE_LINE-----*/
void fdf_make_line(t_line_pts line, t_image *img);
int	my_abs(t_line_pts line_pts, char xy);
t_line_pts change_points(t_line_pts line_pts);
int	calc_offset(t_image *img, t_n_l line, char hb);

/*-----FILL_MAP-----*/
void	fill_map(t_points **map, char **lines, int width, int height);
t_points extract_point(char *value, int x, int y);
void free_split(char **split_line);
t_points extract_point(char *value, int x, int y);
char *extract_color(char *value);
char *extract_z_value(char *value);

/*-----BUILD_MAP-----*/
t_points **allocate_map(int width, int height);
void print_map(t_points **map, int width, int height);
void free_map(t_map *map);
void	free_map_lines(char **lines, int height);
char	**read_map_file(const char *filename, int *width, int *height);
int add_line_to_map(char ***lines, char *line, int height);
int count_columns(char *line);
void	**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size);
t_map build_map(const char *filename);