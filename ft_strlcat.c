/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:33:17 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/06 12:01:31 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
        size_t  j;

	i = 0;
        j = 0;
	if (size <= 0)
	{
		return (size);
	}
        while (dst[i])
        {
                i++; 
        }
	while (src[j] && size - 1)
	{
		dst[i] = src[j];
		i++;
                j++;
	}
	dst[i] = '\0';
	return (i);
}

// int	main(void)
// {
// 	char dst[50] = "coucou je m'appel";
// 	const char *src = " Nathan";
// 	int length;

// 	length = 45;
// 	printf("avant: ");

// 	printf("%s", dst);

// 	printf("\n");

// 	printf("apres: ");

// 	ft_strlcat(dst, src, length);

// 	printf("%s", dst);

// }