/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:54:09 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/06 18:38:15 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char * ft_strnstr(const char *big, const char *little, size_t len)
{
        size_t  i;
        size_t  j;
        size_t  little_len;
        
        i = 0;
        j = 0;
        little_len = 0;
        if (little[i] == '\0')
        {
                return ((char *)big);
        }
        
        while (little[little_len])
        {
                little_len ++;
        }
        
        while (big[i] && i != len)
        {
                if (big[i] == little[j])
                {
                        while (big[i] == little[j])
                        {
                                if (little[little_len - 1] == big[i])
                                {
                                        return ((char *)big + (i - little_len));
                                }
                                i++;
                                j++;
                        }
                }
                i++;
        }
        return (NULL);
        
}

// int     main(void)
// {
//         printf("%s", ft_strnstr("coucou comment tu vas ?", "tu", 17));
// }