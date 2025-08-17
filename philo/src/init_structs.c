/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:02:20 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 00:38:01 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putstr_fd(CALLOC_ERR, STDERR_FILENO), NULL);
	data->nb_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_meals = ft_atoi(argv[5]);
	else
		data->nb_meals = -1;
	pthread_mutex_init(&data->log_mutex, NULL);
	pthread_mutex_init(&data->sim_mutex, NULL);
	data->sim_should_stop = FALSE;
	data->start_time = 0;
	return (data);
}

pthread_mutex_t	*init_forks(int nb_philos)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = ft_calloc(nb_philos, sizeof(*forks));
	if (!forks)
		return (ft_putstr_fd(CALLOC_ERR, STDERR_FILENO), NULL);
	while (i < nb_philos)
		pthread_mutex_init(&forks[i++], NULL);
	return (forks);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = ft_calloc(data->nb_philos, sizeof(t_philo));
	if (!philos)
		return (ft_putstr_fd(CALLOC_ERR, STDERR_FILENO), NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].last_meal_time = 0;
		philos[i].left_fork = &data->forks[i];
		philos[i].left_fork_id = i;
		philos[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
		philos[i].right_fork_id = (i + 1) % data->nb_philos;
		philos[i].meals_eaten = 0;
		pthread_mutex_init(&philos[i].philo_state_mutex, NULL);
		i++;
	}
	return (philos);
}
