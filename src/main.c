/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:41:23 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/31 12:43:34 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// main function. 
// initialize the program, initialize all the forks, initialize all the philos,
// create the threads and run the program
int	main(int argc, char **argv)
{
	int				*num;
	t_monitor		monitor;
	pthread_mutex_t	forks[200];
	t_philo			philos[200];

	if (argc == 5 || argc == 6)
	{
		num = pass_argv_num(argc, argv);
		if (check_chars(num, argc) == 0)
		{
			init_program(&monitor, philos);
			init_forks(forks, ft_atoi(argv[1]));
			init_philos(philos, &monitor, forks, argv);
			thread_create(&monitor, forks);
		}
		else
			printf("Invalid arguments\n");
		free(num);
	}
	else
		printf("Invalid number of arguments\n");
}
