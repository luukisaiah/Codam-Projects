/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_all.c                                    :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 14:51:58 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:16:17 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_all(char **argv, t_program *program,
	t_philosopher *philos, pthread_mutex_t *forks)
{
	int	program_init;	
	int	forks_init;
	int	philosophers_init;

	program_init = initialize_program(program, argv);
	if (program_init <= 2)
	{
		handle_error_program(program, program_init);
		return (FAILURE);
	}
	program->philosophers = philos;
	forks_init = initialize_forks(program, forks);
	if (forks_init != program->num_philos)
	{
		handle_error_program(program, 2);
		handle_error_forks(forks, forks_init);
		return (FAILURE);
	}
	philosophers_init = initialize_philosophers(program, philos, forks);
	if (philosophers_init != program->num_philos)
	{
		handle_clean_all(program, forks, philosophers_init);
		return (FAILURE);
	}
	return (SUCCESS);
}
