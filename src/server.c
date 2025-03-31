/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:01:44 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/31 19:17:12 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// void bin_to_char(int signum, char* c)
// {
// /**
//  * if (signum == SIGUSR1) *c = (*c << 1) | 1;
//  * else if (signum == SIGUSR2) *c <<= 1;
// */
// }

void sig_handler(int signum, siginfo_t* info, void* more_info)
{
	(void)more_info;
	static char	c;
	static int	bit;

}

int main(void)
{
	ft_printf("Server PID = %d", getpid());Signal(SIGUSR1, sig_handler, true);
	Signal(SIGUSR2, sig_handler, true);while (1)
		pause();
	 return EXIT_SUCCESS;
}