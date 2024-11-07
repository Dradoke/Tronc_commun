/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:18:14 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/10/28 17:18:14 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*strchr(const char *str, int c)
{
	size_t i;

	i = 0;

	while (str[i])
	{
		if (str[i] == c)
		{
			return (str[i]);
		}
                i++;
	}
        return (NULL);
}

int     main(void)
{
        printf("%s", strchr("coucou c'est moi", 'e'));
}