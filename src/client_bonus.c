/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:33:27 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/02 18:33:29 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_srv = BUSY;

void	end_handler(int signal)
{
	(void)signal;
	ft_printf("\n\t✅ Message received ✅\n");
	exit(EXIT_SUCCESS);
}

void	active_handler(int signal)
{
	(void)signal;
	g_srv = READY;
}

void	send_char(char c, pid_t srv)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			my_kill(srv, SIGUSR1);
		else
			my_kill(srv, SIGUSR2);
		bit++;
		while (BUSY == g_srv)
			sleep(0.042);
		g_srv = BUSY;
	}
}

int	main(int argc, char **argv)
{
	pid_t	srv;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage = ./bin/minitalk <PID> '\'Message'\'\n");
		return (EXIT_FAILURE);
	}
	srv = ft_atoi(argv[1]);
	message = argv[2];
	my_signal(SIGUSR1, active_handler, false);
	my_signal(SIGUSR2, end_handler, false);
	i = 0;
	while (message[i])
		send_char(message[i++], srv);
	send_char('\0', srv);
	return (EXIT_SUCCESS);
}
