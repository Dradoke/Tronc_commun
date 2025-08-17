/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:50:29 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 17:01:49 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *curr_philo)
{
	philo_print(curr_philo, THINK_MSG);
}

void	take_forks(t_philo *curr_philo)
{
	int	a;
	int	b;
	int	first;
	int	second;

	a = curr_philo->left_fork_id;
	b = curr_philo->right_fork_id;
	if (a < b)
	{
		first = a;
		second = b;
	}
	else
	{
		first = b;
		second = a;
	}
	pthread_mutex_lock(&curr_philo->data->forks[first]);
	philo_print(curr_philo, TAKE_FORK_MSG);
	pthread_mutex_lock(&curr_philo->data->forks[second]);
	philo_print(curr_philo, TAKE_FORK_MSG);
}

void	putback_forks(t_philo *curr_philo)
{
	pthread_mutex_unlock(curr_philo->left_fork);
	pthread_mutex_unlock(curr_philo->right_fork);
}

void	eat(t_philo *curr_philo)
{
	int	a;
	int	b;
	int	first;
	int	second;

	a = curr_philo->left_fork_id;
	b = curr_philo->right_fork_id;
	pthread_mutex_lock(&curr_philo->philo_state_mutex);
	curr_philo->last_meal_time = get_curtime_ms();
	curr_philo->meals_eaten++;
	pthread_mutex_unlock(&curr_philo->philo_state_mutex);
	philo_print(curr_philo, EATING_MSG);
	smart_usleep(curr_philo, curr_philo->data->time_to_eat);
	if (a < b)
	{
		first = a;
		second = b;
	}
	else
	{
		first = b;
		second = a;
	}
	pthread_mutex_unlock(&curr_philo->data->forks[first]);
	pthread_mutex_unlock(&curr_philo->data->forks[second]);
}

void	philo_sleep(t_philo *curr_philo)
{
	philo_print(curr_philo, SLEEP_MSG);
	smart_usleep(curr_philo, curr_philo->data->time_to_eat);
}
