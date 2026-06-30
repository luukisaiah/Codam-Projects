/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_forks.c                                  :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 16:44:32 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:16:32 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_forks(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (i);
		i++;
	}
	return (i);
}
