/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:30:58 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:09 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

// int     main(int argc, char **argv)
// {
//         if (argc < 2)
//         {
//                 return (0);
//         }
//         else
//         {
//                 printf("the length is: %d", ft_strlen(argv[1]));
//         }
// }