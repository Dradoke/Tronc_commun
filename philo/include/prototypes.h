/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:13:47 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/08/17 00:49:42 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "structs.h"

/* INIT STRUCTURES*/
t_data			*init_data(char **argv);
pthread_mutex_t	*init_forks(int nb_philos);
t_philo			*init_philo(t_data *data);

/* PHILO UTILS */
long			get_curtime_ms(void);
void			philo_print(t_philo *curr_philo, char *msg);

/* ROUTINE UTILS*/
void			think(t_philo *curr_philo);
void			take_forks(t_philo *curr_philo);
void			putback_forks(t_philo *curr_philo);
void			eat(t_philo *curr_philo);
void			philo_sleep(t_philo *curr_philo);

/* ROUTINE UTILS2 */
t_bool			start_philos(t_philo *philos);

/* ROUTINE */
t_bool			start_philos(t_philo *philos);
void			*philosopher_routine(void *arg);
void			*monitor_routine(void *arg);

/* UTILS */
int				ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);
void			*ft_calloc(size_t nelem, size_t elsize);

/* UTILS2 */
int				ft_isdigit(int c);
#endif