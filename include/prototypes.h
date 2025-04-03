/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:55:22 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/03 15:33:12 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "minitalk.h"

enum
{
	READY,
	BUSY,
};

void	my_signal(int signal, void *handler, bool use_siginfo);
void	my_kill(pid_t pid, int signal);

#endif