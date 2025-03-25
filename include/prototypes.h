/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:53:32 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 12:38:18 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H
# include "fdf.h"


/*-----COLOR_UTILS-----*/
int			bld_clr(t_n_l line, t_line_pts line_pts, t_image *img, char tb);
t_rgba	itorgb(unsigned int color);
int	rgbtoi(t_rgba rgb);
t_rgba	gradient(t_line_pts l);
t_rgba	interpol_color(t_line_pts line_pts);

/*-----DRAW_LINE-----*/
void		wuline(t_line_pts line_pts, t_image *img);
void		draw_line(t_image *img, t_points start, t_points end);
void		draw_hori_line(t_n_l line, t_line_pts line_pts, t_image *img);
void		draw_vert_line(t_n_l line, t_line_pts line_pts, t_image *img);
void		draw_grid(t_image *img, t_map grid);

/*-----DRAW_LINE_UTILS-----*/
int			my_abs(t_line_pts line_pts, char xy);
t_line_pts	change_points(t_line_pts line_pts);
int	calc_offset(t_image *img, t_line_pts line, char hb);
void		my_px_p(t_image *img, int x, int y, int color);

/*-----RASTERIZE-----*/
t_map	rasterize(t_map *tab);
t_tablim	getlim(t_map *tab);
void	drawtabiso(t_image *img, t_map tab);
int	c_abs(int x);
void	swap(void **ptr1, void **ptr2);

/*-----FILL_MAP-----*/
void		fill_map(t_points **map, char **lines, int width, int height);
t_points	extract_point(char *value, int x, int y);
void		free_split(char **split_line);
char		*extract_color(char *value);
char		*extract_z_value(char *value);

/*-----BUILD_MAP-----*/
t_map		build_map(const char *filename);
t_points	**allocate_map(int width, int height);
void		free_map(t_map *map);
void		print_map(t_points **map, int width, int height);

/*-----BUILD_MAP_UTILS-----*/
void		**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size);
int			count_columns(char *line);
char		**read_map_file(const char *filename, int *width, int *height);
int			add_line_to_map(char ***lines, char *line, int height);
void		free_map_lines(char **lines, int height);
void	iter2tab(t_map *src, t_map *dest, t_points (*f)(t_points));
t_points	cartesian_to_screen(t_points point);
void	autozoom(t_map *tab, t_tablim t);
t_map	centermap(t_map *tab, t_tablim t);
void	enlargetab(t_map *tab);

/*-----HOOKS-----*/
int mouse_hook(int button, int x, int y, t_data *app);

/*-----WINDOW-----*/
int	close_window(t_data *data);

/*-----PROGRAMME-----*/
int	key_press(int keysym, t_data *data);
void	init(t_data *data);
#endif
