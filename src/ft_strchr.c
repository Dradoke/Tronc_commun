/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:23:37 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:57 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == ch)
		return ((char *)s + i);
	return (NULL);
}

// int     main(void)
// {
//         char    *s = "coucou Nathan";
//         printf("%s", ft_strchr(s, 'a'));
// }