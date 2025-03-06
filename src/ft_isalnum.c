/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:22:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:19 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
//         printf("test lettre minuscule: %d .\n", ft_isalnum('a'));
//         printf("test lettre Majuscule: %d .\n", ft_isalnum('A'));
//         printf("test chiffre: %d .\n", ft_isalnum('5'));
// }