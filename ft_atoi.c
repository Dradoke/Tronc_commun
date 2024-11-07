/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:08:04 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/06 12:10:50 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	negatif;
	int	result;

	i = 0;
	negatif = 1;
	result = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		{
			i++;
		}
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
			{
				negatif = -1;
			}
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		return (result * negatif);
	}
}

// int     main(void)
// {
//         printf("test pour -1254879: %d", ft_atoi("      -1254879"));
// }