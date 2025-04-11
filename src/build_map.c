/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:45:43 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/11 15:37:17 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	build_tab(const char *filename, t_tab *tab)
{
	static t_tab	new_tab;

	new_tab.height = 0;
	new_tab.lim = (t_tablim){0};
	new_tab.lines = 0;
	new_tab.mtrx = (t_mat4){0};
	new_tab.tab = 0;
	new_tab.width = 0;
	*tab = new_tab;
	if (!read_map_file(tab, filename))
		return (ft_printf("Error: ReadMapFile\n"), 0);
	tab->tab = allocate_map(tab->width, tab->height);
	if (!tab->tab)
	{
		free_map(tab);
		free_map_lines(tab->lines, tab->height);
		return (ft_printf("Error: AllocateMap\n"), 0);
	}
	fill_map(tab->tab, tab->lines, tab->width, tab->height);
	free_map_lines(tab->lines, tab->height);
	return (ft_printf("Success: BuildMap\n"), 1);
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

void	free_map(t_tab *map)
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
