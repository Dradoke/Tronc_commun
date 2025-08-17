/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:00:39 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 18:28:33 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	t_bool	check_args_utils(char *argv)
{
	if (is_sup_int(argv) == TRUE)
		return (ft_putstr_fd(SUPINT_ERR, STDERR_FILENO), FALSE);
	else
		if (ft_atoi(argv) < 0)
			return (ft_putstr_fd(NEG_ERR, STDERR_FILENO), FALSE);
	return (TRUE);
}

static	t_bool	check_args(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	if (argc < 5 || argc > 6)
		return (ft_putstr_fd(NB_ARGS_ERR, STDERR_FILENO), FALSE);
	while (argv[i])
	{
		y = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			y++;
		while (argv[i][y])
		{
			if (!ft_isdigit(argv[i][y++]))
				return (ft_putstr_fd(NINT_ERR, STDERR_FILENO), FALSE);
		}
		if (check_args_utils(argv[i++]) == FALSE)
			return (FALSE);
		if (ft_atoi(argv[1]) < 1)
			return (ft_putstr_fd(MIN_PHILO_ERR, STDERR_FILENO), FALSE);
	}
	return (TRUE);
}

void	init_struct(t_data *data)
{
	data->forks = init_forks(data->nb_philos);
	data->philosophers = init_philo(data);
}

void	init_last_meal(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philosophers[i].philo_state_mutex);
		data->philosophers[i].last_meal_time = data->start_time;
		pthread_mutex_unlock(&data->philosophers[i++].philo_state_mutex);
	}
}

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	monitor_thread_id;
	int			i;

	if (check_args(argc, argv) == FALSE)
		return (1);
	data = init_data(argv);
	init_struct(data);
	data->start_time = get_curtime_ms();
	init_last_meal(data);
	if (start_philos(data->philosophers) == FALSE)
		return (clear_all(data), 1);
	if (pthread_create(&monitor_thread_id, NULL, monitor_routine, data) != 0)
		return (clear_all(data), 1);
	pthread_join(monitor_thread_id, NULL);
	i = 0;
	while (i < data->nb_philos)
		pthread_join(data->philosophers[i++].thread_id, NULL);
	return (clear_all(data), 0);
}
