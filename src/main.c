/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 03:12:58 by razaccar          #+#    #+#             */
/*   Updated: 2024/10/14 14:29:51 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

int	parse_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (0);
	while (++i <= argc - 1)
	{
		if (!ft_isposnum(argv[i]))
			return (0);
		if (ft_atol(argv[i]) <= 0 || ft_atol(argv[i]) > 2147483647)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;

	if (!parse_args(argc, argv))
	{
		printf("%s", ERR_ARGS);
		printf("%s%s%s", USAGE, USAGE_ARGS, USAGE_OPT);
		return (1);
	}
	if (simulation_init(&simulation, argc, argv) != 0)
	{
		printf("%s", ERR_INIT);
		return (1);
	}
	simulation_run(&simulation);
	simulation_free(&simulation);
	return (0);
}
