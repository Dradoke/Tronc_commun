/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:18:46 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/20 15:18:46 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void ft_bzero(void *s, size_t n)
{
        char    *ptr = (char    *)s;

        while (n != 0)
        {
                ptr[n-1] = '\0';
                n--;
        }
}

/*
int     main(void)
{
        char    test[] = "coucou";
        int     i = 0;
        int     f = 0;
        int     length = 3;
        
        printf("avant: ");
         while (test[i])
        {
                printf("%c ", test[i]);
                i++;
        }

        printf("\n");

        ft_bzero(&test, 3);

        printf("apres: ");
        while (f < (length + 3))
        {
                printf("%c ", test[f]);
                f++;
        }
}
*/