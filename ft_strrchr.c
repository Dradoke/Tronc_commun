/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:09:27 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/06 17:27:14 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
        size_t i;
        char    ch;

        ch = c;
        i = 0;
        while (s[i])
        {
                i++;
        }
        while (i != 0)
        {
                if (s[i] == ch)
                {
                        return ((char *)s + i);
                }
                i--;
        }
        return (NULL);
        
}

// int     main(void)
// {
//         char    *s = "coucou Nathan";
//         printf("%s", ft_strrchr(s, 'a'));
// }