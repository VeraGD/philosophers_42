/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:36:49 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/31 12:41:13 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_forks_philo(t_philo *philo, pthread_mutex_t *forks, int i)
{
	philo->l_fork = &forks[i];
	if (i == 0)
		philo->r_fork = &forks[philo->n_philo - 1];
	else
		philo->r_fork = &forks[i - 1];
}

int	ft_strlen_double(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

void	init_philos(t_philo *philo, t_monitor *monitor, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].n_philo = ft_atoi(argv[1]);
		philo[i].t_die = (size_t)ft_atoi(argv[2]);
		philo[i].t_eat = (size_t)ft_atoi(argv[3]);
		philo[i].t_sleep = (size_t)ft_atoi(argv[4]);
		philo[i].meals_counter = 0;
		philo[i].start_time = get_time();
		philo[i].last_meal_time = get_time();
		philo[i].id = i + 1;
		philo[i].is_eating = 0;
		philo[i].mutex_die = &monitor->mutex_die;
		philo[i].mutex_meals = &monitor->mutex_meals;
		philo[i].mutex_print = &monitor->mutex_print;
		philo[i].die = &monitor->is_dead;
		init_forks_philo(&monitor->philo[i], forks, i);
		if (ft_strlen_double(argv) == 6)
			philo[i].n_meals = ft_atoi(argv[5]);
		else
			philo[i].n_meals = -1;
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			printf("Mutex fork error\n");
		i++;
	}
}

void	init_program(t_monitor *program, t_philo *philos)
{
	program->is_dead = 0;
	program->philo = philos;
	if (pthread_mutex_init(&program->mutex_print, NULL) != 0)
		printf("Mutex print error\n");
	if (pthread_mutex_init(&program->mutex_die, NULL) != 0)
		printf("Mutex die error\n");
	if (pthread_mutex_init(&program->mutex_meals, NULL) != 0)
		printf("Mutex meals error\n");
}
