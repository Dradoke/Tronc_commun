/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:16:59 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/14 13:41:49 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// int     main(void)
// {
//         printf("test chiffre 0: %d \n", ft_isdigit('0'));
//         printf("test chiffre 5: %d \n", ft_isdigit('5'));
//         printf("test lettre: %d \n", ft_isdigit('a'));
// }