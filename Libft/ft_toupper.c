/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:46:04 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/15 23:46:04 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>


char    ft_toupper(char c)
{
        if (c >= 'a' && c <= 'z')
        {
                return (c - 32);
        }
        return (c);
        
}



int     main(void)
{
        printf("test une lettre: %c", ft_toupper('F'));
}