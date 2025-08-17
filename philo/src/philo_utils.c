/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:01:32 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 13:54:20 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_curtime_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_putstr_fd(GETTIME_ERR, STDERR_FILENO), -1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_print(t_philo *curr_philo, char *msg)
{
	pthread_mutex_lock(&curr_philo->data->log_mutex);
	if (curr_philo->data->sim_should_stop == FALSE)
	{
		printf(msg, get_curtime_ms() - curr_philo->data->start_time,
			curr_philo->id, get_curtime_ms() - curr_philo->last_meal_time);
	}
	pthread_mutex_unlock(&curr_philo->data->log_mutex);
}
