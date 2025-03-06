/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:18:46 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:41 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n != 0)
	{
		ptr[n - 1] = c;
		n--;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	test[] = "coucou";
// 	int		i;
// 	int		f;
// 	int		length;

// 	i = 0;
// 	f = 0;
// 	length = 3;
// 	printf("avant: ");

// 	printf("%s", test);

// 	printf("\n");

// 	printf("apres: ");

// 	printf("%s", ft_memset(&test, 'e', 3));

// }
