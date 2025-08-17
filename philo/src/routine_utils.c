/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:50:29 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 01:35:46 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *curr_philo)
{
	philo_print(curr_philo, THINK_MSG);
}

void	take_forks(t_philo *curr_philo)
{
	if (curr_philo->id % 2 != 0)
	{
		pthread_mutex_lock(curr_philo->left_fork);
		philo_print(curr_philo, TAKE_FORK_MSG);
		pthread_mutex_lock(curr_philo->right_fork);
		philo_print(curr_philo, TAKE_FORK_MSG);
	}
	else
	{
		pthread_mutex_lock(curr_philo->right_fork);
		philo_print(curr_philo, TAKE_FORK_MSG);
		pthread_mutex_lock(curr_philo->left_fork);
		philo_print(curr_philo, TAKE_FORK_MSG);
	}
}

void	putback_forks(t_philo *curr_philo)
{
	pthread_mutex_unlock(curr_philo->left_fork);
	pthread_mutex_unlock(curr_philo->right_fork);
}

void	eat(t_philo *curr_philo)
{
	philo_print(curr_philo, EATING_MSG);
	pthread_mutex_lock(&curr_philo->philo_state_mutex);
	curr_philo->last_meal_time = get_curtime_ms();
	curr_philo->meals_eaten++;
	usleep(curr_philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&curr_philo->philo_state_mutex);
}

void	philo_sleep(t_philo *curr_philo)
{
	philo_print(curr_philo, SLEEP_MSG);
	usleep(curr_philo->data->time_to_sleep * 1000);
}
