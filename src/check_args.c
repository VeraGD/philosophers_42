/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:52:28 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/31 12:55:50 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	r;

	i = 0;
	num = 0;
	r = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			r = -1;
		else
			r = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * num);
}

int	*pass_argv_num(int argc, char **argv)
{
	int	i;
	int	n;
	int	*num;
	int	flag;

	i = 1;
	flag = 0;
	num = (int *)malloc((argc - 1) * sizeof(int));
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		num[i - 1] = n;
		i++;
	}
	return (num);
}

int	check_chars(int *num, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (num[i] < 1 && i != 4)
			return (1);
		if (num[i] > 200 && i == 0)
			return (1);
		if (num[i] < 0 && i == 4)
			return (1);
		i++;
	}
	return (0);
}
