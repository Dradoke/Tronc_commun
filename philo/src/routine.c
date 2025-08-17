/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:00:02 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 16:59:54 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_print(philo, TAKE_FORK_MSG);
		usleep(philo->data->time_to_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&philo->data->sim_mutex);
		if (philo->data->sim_should_stop)
			return (pthread_mutex_unlock(&philo->data->sim_mutex), NULL);
		pthread_mutex_unlock(&philo->data->sim_mutex);
		take_forks(philo);
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

t_bool	check_all_eaten(t_data *data)
{
	int	i;
	int	all_eaten_count;

	if (data->nb_meals == -1)
		return (FALSE);
	i = 0;
	all_eaten_count = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philosophers[i].philo_state_mutex);
		if (data->philosophers[i].meals_eaten >= data->nb_meals)
			all_eaten_count++;
		pthread_mutex_unlock(&data->philosophers[i].philo_state_mutex);
		i++;
	}
	if (all_eaten_count == data->nb_philos)
		return (TRUE);
	return (FALSE);
}

void	stop_prog_die(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->log_mutex);
	printf(DIE_MSG, get_curtime_ms() - data->start_time, philo->id);
	pthread_mutex_unlock(&data->log_mutex);
	pthread_mutex_lock(&data->sim_mutex);
	data->sim_should_stop = TRUE;
	pthread_mutex_unlock(&data->sim_mutex);
	pthread_mutex_unlock(&philo->philo_state_mutex);
}

void	stop_prog_meals(t_data *data)
{
	pthread_mutex_lock(&data->log_mutex);
	data->sim_should_stop = TRUE;
	pthread_mutex_unlock(&data->log_mutex);
}

void	*monitor_routine(void *data_arg)
{
	t_data	*data;
	int		i;
	t_bool	all_eaten_enough;
	t_philo	*philo;

	data = (t_data *)data_arg;
	while (TRUE)
	{
		i = 0;
		all_eaten_enough = TRUE;
		while (i < data->nb_philos)
		{
			philo = &data->philosophers[i++];
			pthread_mutex_lock(&philo->philo_state_mutex);
			if ((get_curtime_ms() - philo->last_meal_time) > data->time_to_die)
				return (stop_prog_die(data, philo), NULL);
			if (data->nb_meals != -1 && philo->meals_eaten < data->nb_meals)
				all_eaten_enough = FALSE;
			pthread_mutex_unlock(&philo->philo_state_mutex);
		}
		if (data->nb_meals != -1 && all_eaten_enough == TRUE)
			return (stop_prog_meals(data), NULL);
		usleep(500);
	}
	return (NULL);
}
