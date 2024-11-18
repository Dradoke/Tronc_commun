/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:00:07 by ngaudoui          #+#    #+#             */
/*   Updated: 2024/11/18 19:00:40 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdarg.h>

int	check_flags(const char *flags)
{
	
}
int	check_format(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == 'c')
	{
		ft_print_char();
	}
}


int	ft_printf(const char *format, ...)
{
	va_list	args;
	
	va_start(args, format);
}

int	main(void)
{
	
}