/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_start_threads.c                               :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/18 14:25:00 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:17:46 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup_threads(t_program *program, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	program->start_time = get_time() + program->num_philos;
	while (i < program->num_philos)
	{
		philosophers[i].start_time = program->start_time;
		if (pthread_create(&(philosophers[i].thread_id), NULL,
				&philo_cycle, &(philosophers[i])) != 0)
			return (-1);
		i++;
	}
	if (pthread_create(&(program->thread), NULL,
			&monitor_philos, program) != 0)
		return (-1);
	return (0);
}

int	start_threads(t_program *program, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < program->num_philos)
	{
		if (pthread_join(philosophers[i].thread_id, NULL) != 0)
			return (-1);
		i++;
	}
	if (pthread_join(program->thread, NULL) != 0)
		return (-1);
	return (0);
}
