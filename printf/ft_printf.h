/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:56:40 by jmilesi           #+#    #+#             */
/*   Updated: 2023/05/26 02:47:17 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

int		ft_pn_b(long long n, char *base);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printpct(void);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *format, ...);

#endif
