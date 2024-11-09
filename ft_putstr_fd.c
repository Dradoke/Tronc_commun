/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 05:16:38 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/09 05:16:38 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}

	size_t len;

	len = ft_strlen(s);
	write(fd, s, len);
}

// int     main(void)
// {
//         ft_putstr_fd("je suis un test", 1);
// }