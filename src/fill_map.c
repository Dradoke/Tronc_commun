/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:43:09 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/11 16:43:49 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fill_map(t_points **map, char **lines, int width, int height)
{
    int		x;
    int		y;
    char	**split_line;

    y = 0;
    while (y < height)
    {
        x = 0;
        split_line = ft_split(lines[y], ' ');
        while (x < width)
        {
            map[y][x] = extract_point(split_line[x], x, y);
            x++;
        }
        free_split(split_line);
        y++;
    }
}

t_points extract_point(char *value, int x, int y)
{
    t_points point;
    char *color_str;

    if (ft_strchr(value, ','))
    {
        char *z_value = strtok(value, ",");
        color_str = strtok(NULL, ",");
        point = (t_points){x, y, ft_atoi(z_value), ft_atoi_base(color_str, 16)};
    }
    else
    {
        point = (t_points){x, y, ft_atoi(value), 0xFFFFFF};
    }
    return point;
}

void free_split(char **split_line)
{
    int x = 0;
    while (split_line[x])
        free(split_line[x++]);
    free(split_line);
}