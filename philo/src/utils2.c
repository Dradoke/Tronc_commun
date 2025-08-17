/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:31:07 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 18:28:04 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_sup_int(const char *chaine)
{
	int			i;
	const char	*int_max_str = "2147483647";
	int			len;

	if (!chaine || *chaine == '\0')
		return (FALSE);
	i = 0;
	len = ft_strlen(chaine);
	if (len > 10)
		return (TRUE);
	if (len < 10)
		return (FALSE);
	while (i < 10)
	{
		if (chaine[i] > int_max_str[i])
			return (TRUE);
		if (chaine[i] < int_max_str[i])
			return (FALSE);
		i++;
	}
	return (FALSE);
}

void	clear_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philosophers[i].philo_state_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->log_mutex);
	pthread_mutex_destroy(&data->sim_mutex);
	free(data->philosophers);
	free(data->forks);
	free(data);
}
