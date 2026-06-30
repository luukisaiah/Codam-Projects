/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_print.c                                       :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/18 15:40:29 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:20:22 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philosopher *philo, char *message)
{
	int	time_stamp;

	pthread_mutex_lock(philo->log_mutex);
	time_stamp = get_time();
	if (!check_philo_dead(philo))
		printf("%d %d %s\n", time_stamp - philo->start_time,
			philo->p_num, message);
	pthread_mutex_unlock(philo->log_mutex);
}
