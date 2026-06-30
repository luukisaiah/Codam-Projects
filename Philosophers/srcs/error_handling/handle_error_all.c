/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_error_all.c                                  :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 12:52:49 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:32:05 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_error_philos(t_program *program, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&program->philosophers[i].eat_mutex);
		i++;
	}
}

void	handle_clean_all(t_program *program, pthread_mutex_t *forks,
	int count)
{
	handle_error_philos(program, count);
	handle_error_forks(forks, program->num_philos);
	handle_error_program(program, 2);
}

void	handle_error_all_exit(t_program *program, pthread_mutex_t *forks)
{
	printf("Error: Thread Creation/Joining Failed\n");
	handle_error_philos(program, program->num_philos);
	handle_error_forks(forks, program->num_philos);
	handle_error_program(program, 2);
	exit (EXIT_FAILURE);
}
