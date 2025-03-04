/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:54 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/04 10:38:59 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx_int.h"
#include "../minilibx/mlx.h"
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
void make_line(t_line_pts line, t_image *img);
int	my_abs(t_line_pts line_pts, char xy);
t_line_pts change_points(t_line_pts line_pts);
int	calc_offset(t_image *img, t_n_l line, char hb);

/*-----DRAW_LINE-----*/
t_points **allocate_map(int width, int height);
void fill_map(t_points **map, char **lines, int width, int height);
void print_map(t_points **map, int width, int height);
void free_map(t_points **map, int width);

char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);