/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:33:17 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:07 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char dst[50];
// 	const char *src = "coucou";
// 	int length;

// 	length = 6;
// 	printf("avant: ");

// 	printf("%s", dst);

// 	printf("\n");

// 	printf("apres: ");

// 	ft_strlcpy(dst, src, length);

// 	printf("%s", dst);
// }