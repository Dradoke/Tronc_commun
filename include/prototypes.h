/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:53:32 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/09 12:37:22 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "fdf.h"

/*-----COLOR_UTILS-----*/
int			bld_clr(t_n_l line, t_line_pts line_pts, char tb);
t_rgb		itorgb(unsigned int color);
int			rgbtoi(t_rgb rgb);
t_rgb		interpol_color_v(t_line_pts line_pts);
t_rgb		interpol_color_h(t_line_pts line_pts);

/*-----DRAW_LINE-----*/
void		wuline(t_line_pts line_pts, t_image *img);
void		draw_line(t_data *data, t_points start, t_points end);
void		draw_hori_line(t_n_l line, t_line_pts line_pts, t_image *img);
void		draw_vert_line(t_n_l line, t_line_pts line_pts, t_image *img);
void		draw_grid(t_data *data);

/*-----DRAW_LINE_UTILS-----*/
int			my_abs(t_line_pts line_pts, char xy);
t_line_pts	change_points(t_line_pts line_pts);
int			calc_offset(t_image *img, t_line_pts line, char hb);
void		my_px_p(t_image *img, int x, int y, int color);

/*-----RASTERIZE-----*/
t_tab		rasterize(t_data *data);
void		getlim(t_tab *tab);
void		drawtabiso(t_data *data);
int			ft_abs(int x);

/*-----FILL_MAP-----*/
void		fill_map(t_points **map, char **lines, int width, int height);
t_points	extract_point(char *value, int x, int y);
void		free_split(char **split_line);
char		*extract_color(char *value);
char		*extract_z_value(char *value);

/*-----BUILD_MAP-----*/
char		build_tab(const char *filename, t_tab *tab);
t_points	**allocate_map(int width, int height);
void		free_map(t_tab *map);

/*-----BUILD_MAP_UTILS-----*/
void		**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size);
int			count_columns(char *line);
char		read_map_file(t_tab *tab, const char *filename);
int			add_line_to_map(char ***lines, char *line, int height);
void		free_map_lines(char **lines, int height);
float		ft_degtorad(float deg);
t_tab		centermap(t_data *data);
void		enlargetab(t_data *data);
int			adjust_coord(t_data *data);

/*-----HOOKS-----*/
int			key_handler(int key, t_data *data);
int			rotate_hook(int key, t_data *data);
int			translate_hook(int key, t_data *data);
int			height_hook(int key, t_data *data);
int			zoom_hook(int key, t_data *data);

/*-----ZOOM-----*/
void		getscale(t_data *data);
void		autozoom(t_data *data);
void		manualzoom(t_data *data);

/*-----WINDOW-----*/
int			close_window(t_data *data);

/*-----PROGRAMME-----*/
char		init(t_data *data);
char		init_img(t_data *data);
#endif
