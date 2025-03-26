/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:59:05 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/26 15:28:41 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <unistd.h>

void	**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size)
{
	void	**new_ptr;
	size_t	i;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
		return (free(ptr), NULL);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < old_size / sizeof(void *))
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

int	count_columns(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i] != '\n')
			count++;
		while (line[i] && line[i] != ' ')
			i++;
	}
	return (count);
}

char	**read_map_file(const char *filename, int *width, int *height)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = NULL;
	*height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*height == 0)
			*width = count_columns(line);
		if (!add_line_to_map(&lines, line, *height))
		{
			close(fd);
			return (free(line), free_map_lines(lines, *height), NULL);
		}
		(*height)++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (lines);
}

int	add_line_to_map(char ***lines, char *line, int height)
{
	char	**temp;

	temp = (char **)ft_realloc_tab((void **)*lines, height * sizeof(char *),
			(height + 1) * sizeof(char *));
	if (!temp)
	{
		free(line);
		free_map_lines(*lines, height);
		return (0);
	}
	*lines = temp;
	(*lines)[height] = line;
	return (1);
}

void	free_map_lines(char **lines, int height)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (i < height)
		free(lines[i++]);
	free(lines);
}
