/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:07:04 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:28 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	n_length(long nbr, int len)
{
	int	count;

	count = len;
	if (nbr == 0)
	{
		return (1);
	}
	if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	nbr;

	i = 0;
	nbr = n;
	len = n_length(n, 0);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
		i++;
	}
	while (len > i)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

// int	main(void)
// {
//     int test = 25466;
// 	printf("\n%s", ft_itoa(-214748368));
// }