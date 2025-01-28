/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:54:42 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/01/21 15:05:46 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*buff;
	int		byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[byte_read] = 0;
		buffer = ft_free(buffer, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_line(buff[fd]);
	buff[fd] = ft_next(buff[fd]);
	return (line);
}
