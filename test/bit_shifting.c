/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shifting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:29 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/21 10:57:45 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	get_t(int argb)
{
	return ((argb >> 24) & 0xFF);
}

int	get_r(int argb)
{
	return ((argb >> 16) & 0xFF);
}

int	get_g(int argb)
{
	return ((argb >> 8) & 0xFF);
}

int	get_b(int argb)
{
	return (argb & 0xFF);
}
