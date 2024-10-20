/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:18:46 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/20 15:18:46 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n != 0)
	{
		ptr[n - 1] = c;
		n--;
	}
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
// 	while (test[i])
// 	{
// 		printf("%c ", test[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	ft_memset(&test, 'e', 3);
// 	printf("apres: ");
// 	while (f < (length + 3))
// 	{
// 		printf("%c ", test[f]);
// 		f++;
// 	}
// }
