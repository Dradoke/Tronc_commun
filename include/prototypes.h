/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:53:32 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/11 16:07:35 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "fdf.h"

// build_map.c
char		build_tab(const char *filename, t_tab *tab);
t_points	**allocate_map(int width, int height);
void		free_map(t_tab *map);

// build_map_utils.c
void		**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size);
int			count_columns(char *line);
char		read_map_file(t_tab *tab, const char *filename);
int			add_line_to_map(char ***lines, char *line, int height);
void		free_map_lines(char **lines, int height);

// build_map_utils2.c
int			adjust_coord(t_data *data);
t_tab		centermap(t_data *data);
void		enlargetab(t_data *data);
float		ft_degtorad(float deg);

// color_utils.c
t_rgb		itorgb(unsigned int color);
int			rgbtoi(t_rgb rgb);
t_rgb		interpol_color_v(t_line_pts line_pts);
t_rgb		interpol_color_h(t_line_pts line_pts);
int			bld_clr(t_n_l line, t_line_pts line_pts, char tb);

// draw_line.c
void		draw_hori_line(t_n_l line, t_line_pts line_pts, t_image *img);
void		draw_vert_line(t_n_l line, t_line_pts line_pts, t_image *img);
void		wuline(t_line_pts line_pts, t_image *img);
void		draw_grid(t_data *data);
void		draw_line(t_data *data, t_points start, t_points end);

// draw_line_utils.c
int			my_abs(t_line_pts line_pts, char xy);
t_line_pts	change_points(t_line_pts line_pts);
int			calc_offset(t_image *img, t_line_pts line, char hb);
void		my_px_p(t_image *img, int x, int y, int color);

// fdf.c
char		init_img(t_data *data);
char		init(t_data *data);
int			main(int argc, char **argv);

// fill_map.c
void		fill_map(t_points **map, char **lines, int width, int height);
t_points	extract_point(char *value, int x, int y);
char		*extract_color(char *value);
char		*extract_z_value(char *value);
void		free_split(char **split_line);

// hooks.c
int			key_handler(int key, t_data *data);
int			rotate_hook(int key, t_data *data);
int			translate_hook(int key, t_data *data);
int			height_hook(int key, t_data *data);
int			zoom_hook(int key, t_data *data);

// rasterize.c
void		init_matrix(t_data *data, t_mat4 *m);
void		apply_mat4(t_points *p, t_mat4 *m);
t_tab		rasterize(t_data *data);
void		restoretab(t_data *data);
void		drawtabiso(t_data *data);

// window.c
int			close_window(t_data *data);

// zoom.c
void		getscale(t_data *data);
void		autozoom(t_data *data);
void		manualzoom(t_data *data);
void		getlim(t_tab *tab);
#endif
