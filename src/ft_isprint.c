/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:36:55 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:26 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
	{
		return (1);
	}
	return (0);
}

// int     main(void)
// {
//         printf("test lettre minuscule: %d .\n", ft_isprint('a'));
//         printf("test lettre Majuscule: %d .\n", ft_isprint('A'));
//         printf("test chiffre: %d .\n", ft_isprint('5'));
//         printf("test espace: %d .\n", ft_isprint(' '));
//         printf("test non printable: %d .\n", ft_isprint(31));
// }