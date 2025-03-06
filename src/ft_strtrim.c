/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:54 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:21 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
	{
		return (NULL);
	}
	ft_strlcpy(trimmed, &s1[start], (end - start + 1));
	trimmed[end - start] = '\0';
	return (trimmed);
}
// int	main(void)
// {
// printf("%s", ft_strtrim( "lorem \n ipsum 
//\t dolor \n sit \t amet"," "));
// }