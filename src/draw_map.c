/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:45:43 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/28 00:46:37 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void draw_map()
// {
//  int  x;
//  int  y;

//  x = 0;
//  while (x < WIN_WIDTH)
//  {
//   y = 0;
//   while (y < WIN_HEIGHT)
//   {
//    draw_line(x, y, x + 1, y);
//    draw_line(x, y, x, y + 1);
//    y++;
//   }
//   x++;
//  }
// }

t_points **allocate_map(int width, int height)
{
    t_points **map;
    int x;

    map = malloc(sizeof(t_points *) * width);
    if (!map)
        return (NULL);
    while (x < width)
    {
        map[x] = malloc(sizeof(t_points) * height);
        if (!map[x])
        {
            while (x-- > 0)
                free(map[x]);
            free(map);
            return(NULL);
        }
    }
    return (map);
}
void free_map(t_points **map, int width)
{
    for (int x = 0; x < width; x++)
        free(map[x]);
    free(map);
}
void fill_map(t_points **map, char **lines, int width, int height)
{
    int x, y;
    char **split_line;

    for (y = 0; y < height; y++)
    {
        split_line = ft_split(lines[y], ' '); // Séparer la ligne en tokens
        for (x = 0; x < width; x++)
        {
            map[x][y] = (t_points){x, y, atoi(split_line[x]), 0xFFFFFF}; // Blanc par défaut
        }
        free(split_line);
    }
}