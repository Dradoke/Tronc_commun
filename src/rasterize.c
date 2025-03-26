/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:06:10 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/26 15:34:43 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#define M_PI 3.14159265358979323846

t_map	rasterize(t_map *tab)
{
	int		y;
	int		x;
	double	temp_x;
	double	temp_y;

	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			temp_x = tab->tab[x][y].x;
			temp_y = tab->tab[x][y].y;
			tab->tab[x][y].x = (temp_x - temp_y) * cos(M_PI / 6);
			tab->tab[x][y].y = (temp_x + temp_y) * sin(M_PI / 6)
				- tab->tab[x][y].z;
			tab->tab[x][y].sx = (int)tab->tab[x][y].x;
			tab->tab[x][y].sy = (int)tab->tab[x][y].y;
			x++;
		}
		y++;
	}
	return (*tab);
}

t_tablim	getlim(t_map *tab)
{
	int			y;
	int			x;
	t_tablim	t;

	ft_memset(&t, 0, sizeof(t_tablim));
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			if (tab->tab[x][y].sx <= t.xmin)
				t.xmin = tab->tab[x][y].sx;
			if (tab->tab[x][y].sx >= t.xmax)
				t.xmax = tab->tab[x][y].sx;
			if (tab->tab[x][y].sy <= t.ymin)
				t.ymin = tab->tab[x][y].sy;
			if (tab->tab[x][y].sy >= t.ymax)
				t.ymax = tab->tab[x][y].sy;
			x++;
		}
		y++;
	}
	return (t);
}

void	drawtabiso(t_image *img, t_map tab)
{
	enlargetab(&tab);
	rasterize(&tab);
	centermap(&tab, getlim(&tab));
	autozoom(&tab, getlim(&tab));
	iter2tab(&tab, &tab, cartesian_to_screen);
	draw_grid(img, tab);
}

int	c_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	swap(void **ptr1, void **ptr2)
{
	void	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
