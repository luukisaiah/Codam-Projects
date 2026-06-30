/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_eat_count.c                                   :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 14:32:27 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:25:13 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat_count(t_program *program)
{
	int	i;
	int	count;
	int	all_done;

	if (program->meal_count == -1)
		return (1);
	i = 0;
	all_done = 1;
	while (i < program->num_philos)
	{
		pthread_mutex_lock(&program->philosophers[i].eat_mutex);
		count = program->philosophers[i].meal_count;
		pthread_mutex_unlock(&program->philosophers[i].eat_mutex);
		if (count < program->meal_count)
			all_done = 0;
		i++;
	}
	if (all_done)
	{
		pthread_mutex_lock(&program->dead_mutex);
		program->died = 1;
		pthread_mutex_unlock(&program->dead_mutex);
		return (0);
	}
	return (1);
}
