/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:36:05 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/31 12:36:31 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	thread_create(t_monitor *program, pthread_mutex_t *forks)
{
	pthread_t	monitor_t;
	int			i;

	i = 0;
	if (pthread_create(&monitor_t, NULL, &monitor, program->philo) != 0)
		destory_all("Thread creation error", program, forks);
	while (i < program->philo[0].n_philo)
	{
		if (pthread_create(&program->philo[i].thread, NULL, &philo_routine,
				&program->philo[i]) != 0)
			destory_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor_t, NULL) != 0)
		destory_all("Thread join error", program, forks);
	while (i < program->philo[0].n_philo)
	{
		if (pthread_join(program->philo[i].thread, NULL) != 0)
			destory_all("Thread join error", program, forks);
		i++;
	}
	return (0);
}
