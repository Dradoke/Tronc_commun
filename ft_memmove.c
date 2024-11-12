/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:19:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/12 17:30:01 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char *destination;
	const unsigned char *source;

	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;

	if (destination == source || n == 0)
	{
		return (dest);
	}
	
	if (destination > source)
	{
		while (n > 0)
		{
			n--;
			destination[n] = source[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dest);
}

// int main(void)
// {
// 	char dest[] = "bonjour toi";
// 	char src[] = "coucou";
// 	int length = 6;
// 	ft_memmove(dest, src, length);
// 	printf("dest = %s \n", dest);
// }