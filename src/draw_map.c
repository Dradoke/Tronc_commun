/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:45:43 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/02/26 02:19:44 by ngaudoui         ###   ########.fr       */
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

    // Allocation des colonnes (X)
    map = malloc(sizeof(t_points *) * width);
    if (!map)
        return (NULL);
    
    // Allocation des lignes (Y)
    for (x = 0; x < width; x++)
    {
        map[x] = malloc(sizeof(t_points) * height);
        if (!map[x])
        {
            while (x-- > 0)
                free(map[x]);
            free(map);
            return (NULL);
        }
    }
    return (map);
}