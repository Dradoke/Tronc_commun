/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:45:43 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/26 15:37:09 by ngaudoui         ###   ########.fr       */
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
