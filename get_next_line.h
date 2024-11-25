/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:14:27 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/25 18:16:28 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line
# define get_next_line
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*join_and_free(char *s1, char *s2);
char	*get_next_line(int fd);
char	*extract_line(char	**buffer);
char	*ft_strcpy(char	*dest, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_strdup(const char *s);

#endif