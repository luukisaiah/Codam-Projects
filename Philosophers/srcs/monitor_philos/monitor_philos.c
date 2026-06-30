/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor_philos.c                                    :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 17:47:27 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:25:57 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_philos(void *parameter)
{
	t_program	*program;

	program = (t_program *)parameter;
	harmonize_philos_start(program->start_time + 10);
	while (1)
	{
		if (!check_eat_count(program))
			break ;
		if (!check_ttdie_philos(program))
			break ;
		ft_usleep(5);
	}
	return (NULL);
}
