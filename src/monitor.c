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

// Checks if the philosopher is dead

int	philosopher_dead(t_philo *philo, size_t t_die)
{
	pthread_mutex_lock(philo->mutex_meals);
	if (get_time() - philo->last_meal_time >= t_die
		&& philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->mutex_meals), 1);
	pthread_mutex_unlock(philo->mutex_meals);
	return (0);
}

// Check if any philo died

int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].n_philo)
	{
		if (philosopher_dead(&philos[i], philos[i].t_die))
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_l}
