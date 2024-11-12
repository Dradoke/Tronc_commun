/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:28:27 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/06 17:52:26 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i;
        
        i = 0;
        while (i != n && (s1[i] && s2[i]) && (s1[i] == s2[i]))
        {
                i++;
        }
        return (s1[i] - s2[i]);
}

// int     main(void)
// {
//         printf("%d", ft_strncmp("coucou", "coucou", 6));
// }