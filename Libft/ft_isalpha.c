/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:35:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/15 23:35:12 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_isalpha(int  c)
{
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
                return (1);
        }
        return (0);
}

// int     main(void)
// {
//         printf("lettre minuscule: %d \n", ft_isalpha('a'));
//         printf("lettre majuscule: %d \n", ft_isalpha('A'));
//         printf("chiffre: %d \n", ft_isalpha('1'));
// }