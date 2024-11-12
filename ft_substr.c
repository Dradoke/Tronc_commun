/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:00:09 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/07 16:00:09 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_length;
	char	*substring;

	s_length = (ft_strlen(s) + 1);
	if (start > s_length)
	{
		return (NULL);
	}
	if (start + len > s_length)
	{
		len = s_length - start;
	}
	substring = malloc(len);
	ft_strlcpy(substring, &s[start], len);
	return (substring);
}

// int	main(void)
// {
// 	printf("%s", ft_substr("coucou je m'appel Nathan", 7, 17));
// }