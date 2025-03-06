/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:19:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:36 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char dest[] = "bonjour";
// 	char src[] = "coucou";
// 	int length = 3;

// 	printf("dest = %s \n", ft_memcpy(dest, src, length));
// }