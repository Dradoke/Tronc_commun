/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:01:32 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 16:57:37 by ngaudoui         ###   ########.fr       */
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
	long	cur;
	long	since_start;
	long	since_meal;

	pthread_mutex_lock(&curr_philo->philo_state_mutex);
	pthread_mutex_lock(&curr_philo->data->log_mutex);
	if (curr_philo->data->sim_should_stop)
	{
		pthread_mutex_unlock(&curr_philo->data->log_mutex);
		pthread_mutex_unlock(&curr_philo->philo_state_mutex);
		return ;
	}
	cur = get_curtime_ms();
	since_start = cur - curr_philo->data->start_time;
	since_meal = cur - curr_philo->last_meal_time;
	printf(msg, since_start, curr_philo->id, since_meal);
	pthread_mutex_unlock(&curr_philo->data->log_mutex);
	pthread_mutex_unlock(&curr_philo->philo_state_mutex);
}
