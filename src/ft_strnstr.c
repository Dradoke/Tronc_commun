/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:54:09 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:15 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;
	char	*ptr_str;

	i = 0;
	little_len = ft_strlen(little);
	ptr_str = (char *)big;
	if (little_len == 0 || big == little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0'
			&& big[i + j] == little[j] && i + j < len)
			j++;
		if (j == little_len)
			return (ptr_str + i);
		i++;
	}
	return (0);
}

// int     main(void)
// {
//         printf("%s", ft_strnstr("aaabcabcd", "aabc", -1));
// }