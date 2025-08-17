/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:29:31 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 00:29:53 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	start_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL,
				philosopher_routine, &philos[i]) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
