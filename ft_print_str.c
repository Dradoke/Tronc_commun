/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:33:17 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/18 17:59:13 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_print_str(char *str)
{
	size_t	len;

	if (!str)
	{
		return (0);
	}
	len = ft_strlen(str);
	write(1, str, len);   
	return (len);
}