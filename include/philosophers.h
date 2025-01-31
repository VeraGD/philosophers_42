/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:00:12 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/31 13:09:09 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id; // id
	pthread_t		thread; // thread
	int				meals_counter; // how many meals philo take
	size_t			start_time; // current time
	size_t			last_meal_time; // time of its last meal
	int				n_philo; // number philos
	int				*die; // if philo has died
	int				is_eating; // if philo is eating
	size_t			t_die; // time to died since last meal or begining
	size_t			t_eat; // time to eat
	size_t			t_sleep; // time to sleep
	int				n_meals; // number meals until stop
	pthread_mutex_t	*l_fork; // mutex left fork
	pthread_mutex_t	*r_fork; // mutex right fork
	pthread_mutex_t	*mutex_die; // Mutex para la variable die
	pthread_mutex_t	*mutex_meals; // Mutex para meals
	pthread_mutex_t	*mutex_print; // Mutex para print messagges
}	t_philo;

typedef struct s_monitor
{
	int				is_dead; // someone is dead
	t_philo			*philo; // philos
	pthread_mutex_t	mutex_die; // Mutex para la variable die
	pthread_mutex_t	mutex_meals; // Mutex para meals
	pthread_mutex_t	mutex_print; // Mutex para print messagges
}	t_monitor;

// Utils
size_t	get_time(void);
void	destory_all(char *str, t_monitor *monitor, pthread_mutex_t *forks);
int		ft_usleep(size_t milliseconds);

// Check
int		*pass_argv_num(int argc, char **argv);
int		check_chars(int *num, int argc);

// Ini
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_philos(t_philo *philos, t_monitor *program, pthread_mutex_t *forks,
			char **argv);
void	init_program(t_monitor *program, t_philo *philos);
int		ft_atoi(const char *nptr);

// dinner
int		thread_create(t_monitor *program, pthread_mutex_t *forks);

// philo_routine
void	*philo_routine(void *param);
int		dead_loop(t_philo *philo);

// monitor
void	*monitor(void *pointer);
void	print_message(char *str, t_philo *philo, int id);

#endif
