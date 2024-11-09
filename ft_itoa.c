/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:07:04 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/08 23:07:04 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	n_length(int nbr, int len)
{
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	printf("len = %d", len);
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	char	sign;

	len = 1;
	printf("nbr = %d\n", n);
	len = n_length(n, len);
	if (n < 0)
	{
		n *= -1;
		sign = '-';
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign == '-')
		str[0] = sign;
	while (n >= 10)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	str[--len] = (n % 10) + '0';
	return (str);
}

// int	main(void)
// {
//     int test = 25466;
// 	printf("\n%s", ft_itoa(547));
// }