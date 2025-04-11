/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:01:44 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/11 12:23:40 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *more_info)
{
	static char		c;
	static int		bit;
	static pid_t	pid;

	(void)more_info;
	if (info->si_pid)
		pid = info->si_pid;
	if (SIGUSR1 == signal)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signal)
		c &= ~(0x80 >> bit);
	bit++;
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			my_kill(pid, SIGUSR2);
			c = 0;
			return (ft_printf("\n"), (void)1);
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	my_kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Usage: ./bin/server\n");
		return (EXIT_FAILURE);
	}
	ft_printf("Server PID = %d\n", getpid());
	my_signal(SIGUSR1, sig_handler, true);
	my_signal(SIGUSR2, sig_handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
