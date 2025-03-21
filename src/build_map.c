/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:45:43 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/21 10:35:50 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	build_map(const char *filename)
{
	t_map	map;

	map.lines = read_map_file(filename, &map.width, &map.height);
	if (!map.lines)
		return (map);
	map.tab = allocate_map(map.width, map.height);
	if (!map.tab)
	{
		free_map(&map);
		return (map);
	}
	fill_map(map.tab, map.lines, map.width, map.height);
	print_map(map.tab, map.width, map.height);
	return (map);
}

t_points	**allocate_map(int width, int height)
{
	t_points	**map;
	int			x;

	x = 0;
	map = malloc(sizeof(t_points *) * height);
	if (!map)
		return (NULL);
	while (x < height)
	{
		map[x] = malloc(sizeof(t_points) * width);
		if (!map[x])
		{
			while (x-- > 0)
				free(map[x]);
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
	if (map->lines)
		free_map_lines(map->lines, map->height);
	if (map->tab)
	{
		i = 0;
		while (i < map->height)
			free(map->tab[i++]);
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
	while (idx.iy < height)
	{
		while (idx.ix < width)
		{
			ft_printf("%d\t", map[idx.iy][idx.ix].z);
			idx.ix++;
		}
		ft_printf("\n");
		idx.ix = 0;
		idx.iy++;
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
