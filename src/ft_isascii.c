/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:32:23 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:22 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
	{
		return (1);
	}
	return (0);
}

// int     main(void)
// {
//         printf("test lettre minuscule: %d .\n", ft_isascii('a'));
//         printf("test lettre Majuscule: %d .\n", ft_isascii('A'));
//         printf("test chiffre: %d .\n", ft_isascii('5'));
//         printf("test espace: %d .\n", ft_isascii(' '));
//         printf("test +: %d .\n", ft_isascii('+'));
// }