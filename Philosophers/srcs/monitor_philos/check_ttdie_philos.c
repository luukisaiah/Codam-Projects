/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_ttdie_philos.c                                :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 14:57:50 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:26:27 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ttdie_philos(t_program *program)
{
	int	i;
	int	time;

	i = 0;
	while (i < program->num_philos)
	{
		pthread_mutex_lock(&program->philosophers[i].eat_mutex);
		time = get_time() - program->philosophers[i].last_meal;
		pthread_mutex_unlock(&program->philosophers[i].eat_mutex);
		if (time >= program->tt_die)
		{
			ft_print(&program->philosophers[i], "died");
			pthread_mutex_lock(program->philosophers[i].dead_mutex);
			*(program->philosophers[i].is_dead) = 1;
			pthread_mutex_unlock(program->philosophers[i].dead_mutex);
			return (0);
		}
		i++;
	}
	return (1);
}
