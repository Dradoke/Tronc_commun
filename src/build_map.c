/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:45:43 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/25 15:10:54 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	build_map(const char *filename)
{
	t_map	map;
	map.lines = read_map_file(filename, &map.width, &map.height);
	if (!map.lines)
		return (map);
	ft_printf("map height: %d, map width: %d\n", map.height, map.width);
	map.tab = allocate_map(map.width, map.height);
	if (!map.tab)
	{
		free_map(&map);
		free_map_lines(map.lines, map.height);
		return (map);
	}
	fill_map(map.tab, map.lines, map.width, map.height);
	free_map_lines(map.lines, map.height);
	return (map);
}

t_points	**allocate_map(int width, int height)
{
	t_points	**map;
	int			x;

	if (width <= 0 || height <= 0)
		return (NULL);
	x = 0;
	map = malloc(sizeof(t_points *) * width);
	if (!map)
		return (NULL);
	while (x < width)
	{
		map[x] = malloc(sizeof(t_points) * height);
		if (!map[x])
		{
			while (x > 0)
			{
				free(map[--x]);
			}
			free(map);
			return (NULL);
		}
		x++;
	}
	return (map);
}

void	free_map(t_map *map)
{
	int	i;
	if (!map)
		return ;
	// if (map->lines)
	// 	free_map_lines(map->lines, map->height);
	if (map->tab)
	{
		i = 0;
		while (i < map->width)
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
	}
	map->lines = NULL;
	map->tab = NULL;
	map->width = 0;
	map->height = 0;
}

void	print_map(t_points **map, int width, int height)
{
	t_index	idx;
	(void) map;
	idx.ix = 0;
	idx.iy = 0;
	while (idx.ix < width)
	{
		while (idx.iy < height)
		{
			printf("%d\t", (int)map[idx.iy][idx.ix].z);
			idx.iy++;
		}
		ft_printf("\n");
		idx.iy = 0;
		idx.ix++;
	}
}

// void print_map(t_points **map, int width, int height)
// {
//     for (int y = 0; y < height; y++)
//     {
//         for (int x = 0; x < width; x++)
//         {
//             ft_printf("(%d, %d, %d, %X) ", 
//                    map[y][x].x, 
//                    map[y][x].y, 
//                    map[y][x].z, 
//                    map[y][x].color);
//             // ft_printf("(%d, %d, %d)  ", 
//             //        map[y][x].x,
// 			// 	   map[y][x].y,
// 			// 	   map[y][x].z);
// 			// ft_printf("%d\t", map[y][x].z);
//         }
//         ft_printf("\n");
//     }
// }
