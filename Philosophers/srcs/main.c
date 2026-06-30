/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                              :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/30 12:21:57 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:15:37 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program		program;	
	t_philosopher	philosophers[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if (!check_input(argc, argv))
	{
		write (2, "Use: ./philo 'number_of_philosophers' 'time_to_die' "
			"'time_to_eat' 'time_to_sleep' "
			"[number_of_times_each_philosopher_must_eat]\n", 127);
		exit(EXIT_FAILURE);
	}
	if (!initialize_all(argv, &program, philosophers, forks))
	{
		write (2, "Error: Initialization Failed\n", 29);
		exit(EXIT_FAILURE);
	}
	if (setup_threads(&program, philosophers) != 0)
		handle_error_all_exit(&program, forks);
	if (start_threads(&program, philosophers) != 0)
		handle_error_all_exit(&program, forks);
	handle_clean_all(&program, forks, philosophers->num_philo);
	exit (EXIT_SUCCESS);
}
