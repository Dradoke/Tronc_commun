/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:38:27 by jmilesi           #+#    #+#             */
/*   Updated: 2023/07/06 08:36:36 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_line(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + line_len(s2) + 2));
	if (dest)
	{
		while (s1 && s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2 && s2[j] != '\0' && s2[j] != '\n')
		{
			dest[i + j] = s2[j];
			j++;
		}
		dest[i + j] = '\n';
		if (s2 && s2[j] != '\0' && s2[j] == '\n')
			j++;
		dest[i + j] = '\0';
	}
	return (ft_free(s1, dest));
}

char	*read_file(char *buffer, char *dest, int fd)
{
	int	i;

	i = 1;
	while (i > 0 && ft_check_line(buffer) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(dest);
			return (NULL);
		}
		buffer[i] = '\0';
		dest = ft_join_line(dest, buffer);
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*dest;

	dest = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (ft_check_line(buff) == 1)
	{
		ft_cut_line(buff);
		dest = ft_join_line(dest, buff);
	}
	dest = read_file(buff, dest, fd);
	return (dest);
}
