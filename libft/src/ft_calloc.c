/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:01 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:17 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	total_size;
	void	*ptr;

	total_size = nelem * elsize;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, total_size);
	return (ptr);
}

// int	main(void)
// {
// 	size_t i = 0;
// 	size_t tab_size = 10;

// 	int *tab = ft_calloc(5, sizeof(int));
// 	while (i != tab_size)
// 	{
// 		printf("test du tableau tab[%d] = %d\n", i, tab[i]);
// 		i++;
// 	}
// }