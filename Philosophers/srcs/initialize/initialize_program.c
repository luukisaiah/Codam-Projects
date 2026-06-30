/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_program.c                                :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 18:18:17 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:17:04 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_program(t_program *program, char **args)
{
	int	count;

	count = 1;
	program->num_philos = ft_atoi(args[1]);
	program->tt_die = ft_atoi(args[2]);
	program->tt_eat = ft_atoi(args[3]);
	program->tt_sleep = ft_atoi(args[4]);
	program->died = 0;
	if (args[5])
		program->meal_count = ft_atoi(args[5]);
	else
		program->meal_count = -1;
	if (pthread_mutex_init(&program->log_mutex, NULL) != 0)
		return (count);
	count++;
	if (pthread_mutex_init(&program->dead_mutex, NULL) != 0)
		return (count);
	count++;
	return (count);
}
