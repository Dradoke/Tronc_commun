/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:18:46 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:15 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n != 0)
	{
		ptr[n - 1] = '\0';
		n--;
	}
}

// int	main(void)
// {
// 		char    test[] = "coucou";
// 	int	i;
// 	int	f;
// 	int	length;

// 		i = 0;
// 		f = 0;
// 		length = ft_strlen(test);
// 		printf("avant: ");
// 			while (test[i])
// 		{
// 				printf("%c ", test[i]);
// 				i++;
// 		}
// 		printf("\n");
// 		ft_bzero(&test, 3);
// 		printf("apres: ");
// 		while (f < (length))
// 		{
// 				printf("%c ", test[f]);
// 				f++;
// 		}
// }