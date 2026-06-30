/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_time.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/17 16:53:53 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:21:33 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
	{
		printf("Error: gettimeofday failed\n");
		return (-1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t mili_s)
{
	size_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < mili_s)
		usleep(100);
	return (start_time);
}

void	harmonize_philos_start(int start)
{
	while (get_time() < start)
		usleep(50);
}
