/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:33:17 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:05 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sizestr;

	i = 0;
	j = 0;
	sizestr = ft_strlen(dst) + ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (dst[i] && i < size)
		i++;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (ft_strlen(dst) < size)
		return (sizestr);
	return (sizestr);
}

// int	main(void)
// {
// 	char dst[50] = "rrrrrr";
// 	const char *src = "lorem ipsum dolor sit amet";
// 	int length;

// 	length = 15;
// 	printf("avant: ");

// 	printf("%s", dst);

// 	printf("\n");

// 	printf("apres: ");

// 	printf("%ld\n",ft_strlcat(dst, src, length));

// 	printf("%s", dst);

// }