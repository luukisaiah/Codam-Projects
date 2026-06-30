/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_error_program.c                              :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/18 14:11:02 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:31:45 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_error_program(t_program *program, int count)
{
	if (count >= 1)
		pthread_mutex_destroy(&program->log_mutex);
	if (count >= 2)
		pthread_mutex_destroy(&program->dead_mutex);
}
