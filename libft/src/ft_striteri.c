/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:50:50 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/06 15:04:01 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
	{
		return ;
	}
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void my_transform(unsigned int i, char *c) {
//     if (i % 2 == 0)
//         *c = ft_toupper(*c); // Majuscule pour les indices pairs
//     else
//         *c = ft_tolower(*c); // Minuscule pour les indices impairs
// }

// int     main(void)
// {
//         char str[] = "coucou C'est moi Nathan";
//         ft_striteri(str, my_transform);
//         printf("Resultat: %s\n", str);
//         return (0);
// }