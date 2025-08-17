/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:22:48 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 14:01:49 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_bool
{
	FALSE,
	TRUE,	
}				t_bool;

typedef struct s_data
{
	int				nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_meals;
	long			start_time;
	t_bool			start_flag;
	t_bool			sim_should_stop;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	*forks;
	struct s_philo	*philosophers;
}				t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal_time;
	int				meals_eaten;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	int				left_fork_id;
	pthread_mutex_t	*right_fork;
	int				right_fork_id;
	pthread_mutex_t	philo_state_mutex;
	t_data			*data;
}				t_philo;
#endif
