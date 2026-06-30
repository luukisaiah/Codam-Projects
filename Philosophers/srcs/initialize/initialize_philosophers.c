/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_philosophers.c                           :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 16:45:33 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:16:46 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_philosophers(t_program *program, t_philosopher *philos,
	pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->num_philos)
	{
		philos[i].p_num = i + 1;
		philos[i].num_philo = program->num_philos;
		philos[i].start_time = 0;
		philos[i].last_meal = 0;
		philos[i].meal_count = 0;
		philos[i].tt_die = program->tt_die;
		philos[i].tt_eat = program->tt_eat;
		philos[i].tt_sleep = program->tt_sleep;
		philos[i].is_dead = &(program->died);
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % program->num_philos];
		philos[i].log_mutex = &(program->log_mutex);
		philos[i].dead_mutex = &(program->dead_mutex);
		if (pthread_mutex_init(&philos[i].eat_mutex, NULL) != 0)
			break ;
		i++;
	}
	return (i);
}
