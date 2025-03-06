/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:30:16 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:12 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
	{
		return (NULL);
	}
	result = malloc(ft_strlen(s) + 1);
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char my_transform(unsigned int i, char c) {
//     if (i % 2 == 0)
//         return (ft_toupper(c)); // Majuscule pour les indices pairs
//     else
//         return (ft_tolower(c)); // Minuscule pour les indices impairs
// }

// int     main(void)
// {
//         printf("%s", ft_strmapi("coucou je suis nathan", my_transform));
// }