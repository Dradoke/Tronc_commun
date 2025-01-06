/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:42:09 by jmilesi           #+#    #+#             */
/*   Updated: 2023/07/06 08:25:41 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_line(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		return (1);
	return (0);
}

int	line_len(char *dest)
{
	int	i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i] != '\0' && dest[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(char *dest)
{
	int	i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i] != '\0')
		i++;
	return (i);
}

void	ft_cut_line(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i] != '\0')
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	buff[j] = '\0';
}

char	*ft_free(char *s1, char *dest)
{
	if (s1)
		free(s1);
	if (dest)
	{
		if (dest[0] == '\0')
		{
			free(dest);
			dest = NULL;
		}
	}
	return (dest);
}
