/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:25:54 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/25 18:02:35 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*extract_line(char	**buffer)
{
	size_t	i;
	size_t	j;
	char	*line;
	char	*remaining;
	i = 0;
	j = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return NULL;
	while (j <= i)
	{
		line[j] = (*buffer)[j];
		j++;
	}
	line[i + 1] = '\0';
	if ((*buffer)[i] == '\n')
		remaining = ft_strdup(&(*buffer)[i + 1]);
	else
		return NULL;
	free(*buffer);
	*buffer = remaining;
	return	line;
}


char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return	(char *)s;
		}
		s++;
	}
	if (c == '\0')
		return (char *)s;
	else
	return NULL;
}
char	*ft_strcpy(char	*dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return	i;
}
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return NULL;
	while (i <= len)
		dup[i] = s[i];
	return	dup;
}