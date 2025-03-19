/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:45:18 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:59 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	s_length;
	char	*s_cpy;

	s_length = (ft_strlen(s) + 1);
	s_cpy = malloc(s_length);
	if (!s_cpy)
	{
		return (NULL);
	}
	ft_strlcpy(s_cpy, s, s_length);
	return (s_cpy);
}

// int     main(void)
// {
//         printf("%s", ft_strdup("coucou je m'appel Nathan"));
// }