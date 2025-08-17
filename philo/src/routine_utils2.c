/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:29:31 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 17:05:17 by ngaudoui         ###   ########.fr       */
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
		i += 2;
	}
	usleep(1000);
	i = 1;
	while (i < philos->data->nb_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL,
				philosopher_routine, &philos[i]) != 0)
			return (FALSE);
		i += 2;
	}
	return (TRUE);
}

void	smart_usleep(t_philo *philo, long duration_ms)
{
	long	start;

	start = get_curtime_ms();
	while (1)
	{
		pthread_mutex_lock(&philo->data->sim_mutex);
		if (philo->data->sim_should_stop)
		{
			pthread_mutex_unlock(&philo->data->sim_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->data->sim_mutex);
		if ((get_curtime_ms() - start) >= duration_ms)
			break ;
		usleep(500);
	}
}
