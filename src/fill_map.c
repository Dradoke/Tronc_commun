/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:43:09 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/11 18:16:45 by ngaudoui         ###   ########.fr       */
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

// t_points extract_point(char *value, int x, int y)
// {
//     t_points point;
//     char *color_str;
// 	// int	i;

//     if (ft_strchr(value, ','))
//     {
// 		printf("VALUE: %s\n", value);
//         char *z_value = strtok(value, ",");
//         color_str = strtok(NULL, ",");
//         point = (t_points){x, y, ft_atoi(z_value), ft_atoi_base(color_str, "0123456789ABCDEF")};
//     }
//     else
//     {
//         point = (t_points){x, y, ft_atoi(value), 0xFFFFFF};
//     }
//     return point;
// }

t_points extract_point(char *value, int x, int y)
{
    t_points point;
    char *z_value;
    char *color;

    z_value = extract_z_value(value);
    color = extract_color(value);
    if (!z_value || !color)
    {
        free(z_value);
        free(color);
        return (t_points){0, 0, 0, 0};
    }
    if (color[0] != '\0')
	{
		// printf("Color: %X\n", ft_atoi_base(color, "0123456789ABCDEF"));
    	point = (t_points){x, y, ft_atoi(z_value), ft_atoi_base(color, "0123456789ABCDEF")};
	}
	else
        point = (t_points){x, y, ft_atoi(z_value), 0xFFFFFF};
    free(z_value);
    free(color);
    return point;
}
char *extract_color(char *value)
{
    int i = 0;
    int j = 0;
    char *color;

    color = ft_calloc(strlen(value) + 1, sizeof(char));
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
	printf("COLOR: %s\n", color);
    return color;
}

char *extract_z_value(char *value)
{
    int i = 0;
    char *z_value;

    z_value = ft_calloc(strlen(value) + 1, sizeof(char));
    if (!z_value)
        return (NULL);
    while (value[i] && value[i] != ',')
    {
        z_value[i] = value[i];
        i++;
    }
    z_value[i] = '\0';
    return z_value;
}

void free_split(char **split_line)
{
    int x = 0;
    while (split_line[x])
        free(split_line[x++]);
    free(split_line);
}