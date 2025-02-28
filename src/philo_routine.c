/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:51:57 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/31 12:52:09 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// think fuction, only print
void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

// Sleep function, print and wait the time (specific argument)
void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->t_sleep);
}

// Eat function, take the forks, eat, increase meals counter, 
// save the time in which they start to it (chaeck dead)
void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->n_philo == 1)
	{
		ft_usleep(philo->t_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, philo->id);
	philo->is_eating = 1;
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->mutex_meals);
	philo->last_meal_time = get_time();
	philo->meals_counter++;
	pthread_mutex_unlock(philo->mutex_meals);
	ft_usleep(philo->t_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

// check if the dead flag of philos is on
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_die);
	if (*philo->die == 1)
		return (pthread_mutex_unlock(philo->mutex_die), 1);
	pthread_mutex_unlock(philo->mutex_die);
	return (0);
}

// Thread routine, eat, sleep, think.
// wait if the philo has a pair number
void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (dead_loop(philo) == 0)
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}
