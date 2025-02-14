/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:56:13 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/31 12:57:47 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->mutex_print);
	time = get_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->mutex_print);
}

int	philosopher_dead(t_philo *philo, size_t t_die)
{
	pthread_mutex_lock(philo->mutex_meals);
	if (get_time() - philo->last_meal_time >= t_die
		&& philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->mutex_meals), 1);
	pthread_mutex_unlock(philo->mutex_meals);
	return (0);
}

int	check_if_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].n_philo)
	{
		if (philosopher_dead(&philo[i], philo[i].t_die))
		{
			print_message("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].mutex_die);
			*philo->die = 1;
			pthread_mutex_unlock(philo[0].mutex_die);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philo)
{
	int	i;
	int	finished_eat;

	i = 0;
	finished_eat = 0;
	if (philo[0].n_meals == -1)
		return (0);
	while (i < philo[0].n_philo)
	{
		pthread_mutex_lock(philo[i].mutex_meals);
		if (philo[i].meals_counter >= philo[i].n_meals)
			finished_eat++;
		pthread_mutex_unlock(philo[i].mutex_meals);
		i++;
	}
	if (finished_eat == philo[0].n_philo)
	{
		pthread_mutex_lock(philo[0].mutex_die);
		*philo->die = 1;
		pthread_mutex_unlock(philo[0].mutex_die);
		return (1);
	}
	return (0);
}

// Monitor thread routine
void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philo) == 1 || check_if_all_ate(philo) == 1)
			break ;
	return (pointer);
}
