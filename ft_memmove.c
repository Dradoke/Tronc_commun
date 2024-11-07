/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:19:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/20 18:19:38 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (destination);
	}
	
	if (destination > source && destination < source + n)
	{
		i = n;
		while (i > 0)
		{
			destination[i] = source[i];
			i--;
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
	return (destination);
}

// int main(void)
// {
// 	char dest[] = "bonjour toi";
// 	char src[] = "coucou";
// 	int length = 0;

// 	printf("dest = %s \n", ft_memmove(dest, src, length));
// }