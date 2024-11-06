/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:57:37 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/14 13:16:25 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

// int     main(void)
// {
//         printf("test lettre minuscule: %d .\n", ft_isalpha('a'));
//         printf("test lettre Majuscule: %d .\n", ft_isalpha('A'));
//         printf("test chiffre: %d .\n", ft_isalpha('5'));
// }