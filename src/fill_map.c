/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:43:09 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/21 17:57:43 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fill_map(t_points **map, char **lines, int width, int height)
{
	int		x;
	int		y;
	t_index	index;
	char	**split_line;

	y = 0;
	index.iy = height / 2 - height;
	// ft_printf("GRID TAB: %d\n", map[x][y].sx);
	while (y < height)
	{
		index.ix = width / 2 - width;
		x = 0;
		split_line = ft_split(lines[y], ' ');
		index.iy++;
		while (x < width)
		{
			map[x][y] = extract_point(split_line[x], ++index.ix, index.iy);
			x++;
		}
		free_split(split_line);
		y++;
	}
}

t_points	extract_point(char *value, int x, int y)
{
	t_points	point;
	char		*z_value;
	char		*color;

	point.color = itorgb(0);
	z_value = extract_z_value(value);
	color = extract_color(value);
	if (!z_value || !color)
	{
		free(z_value);
		free(color);
		return ((t_points){0, 0, 0, itorgb(0), 0, 0});
	}
	if (color[0] != '\0')
		point = (t_points){x, y, ft_atoi(z_value),
			itorgb(ft_atoi_base(color, "0123456789ABCDEF")), 0, 0};
	else
		point = (t_points){x, y, ft_atoi(z_value), itorgb(0xFFFFFF), 0, 0};
	free(z_value);
	free(color);
	return (point);
}

char	*extract_color(char *value)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	j = 0;
	color = ft_calloc(ft_strlen(value) + 1, sizeof(char));
	if (!color)
		return (NULL);
	while (value[i] && value[i] != ',')
		i++;
	if (value[i] == ',')
		i += 3;
	while (value[i])
	{
		color[j++] = value[i++];
	}
	color[j] = '\0';
	return (color);
}

char	*extract_z_value(char *value)
{
	int		i;
	char	*z_value;

	i = 0;
	z_value = ft_calloc(strlen(value) + 1, sizeof(char));
	if (!z_value)
		return (NULL);
	while (value[i] && value[i] != ',')
	{
		z_value[i] = value[i];
		i++;
	}
	z_value[i] = '\0';
	return (z_value);
}

void	free_split(char **split_line)
{
	int	x;

	x = 0;
	while (split_line[x])
		free(split_line[x++]);
	free(split_line);
}
