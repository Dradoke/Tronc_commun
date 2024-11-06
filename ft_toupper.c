/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:46:04 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/06 19:13:27 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int    ft_toupper(int c)
{
        if (c >= 'a' && c <= 'z')
        {
                return (c - 32);
        }
        return (c);
        
}

int     main(void)
{
        printf("test une lettre: %c", ft_toupper('f'));
}