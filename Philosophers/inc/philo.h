/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                             :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/02 12:14:05 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/18 14:14:48 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define MAX_PHILO 200

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define SUCCESS 1
# define FAILURE 0

typedef enum s_state
{
	EATING,
	SLEEPING,
	THINKING
}	t_state;

typedef struct s_philosopher
{
	int					p_num;
	int					num_philo;
	int					start_time;
	int					last_meal;
	int					meal_count;
	t_state				state;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					*is_dead;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*log_mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		*dead_mutex;
}	t_philosopher;

typedef struct s_program
{
	int					num_philos;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					died;
	int					meal_count;
	int					start_time;
	pthread_mutex_t		log_mutex;
	pthread_mutex_t		dead_mutex;
	t_philosopher		*philosophers;
	pthread_t			thread;
}	t_program;

//validate_input
int		check_input(int argc, char **argv);

//utils
int		ft_atoi(const char *str);
int		get_time(void);
int		ft_usleep(size_t mili_s);
void	harmonize_philos_start(int start);
void	ft_print(t_philosopher *philo, char *message);

//initialization
int		initialize_all(char **args, t_program *program,
			t_philosopher *philosophers, pthread_mutex_t *forks);
int		initialize_program(t_program *program, char **args);
int		initialize_forks(t_program *program, pthread_mutex_t *forks);
int		initialize_philosophers(t_program *program, t_philosopher *philos,
			pthread_mutex_t *forks);

//handle_errors 
void	handle_error_program(t_program *program, int count);
void	handle_error_forks(pthread_mutex_t *forks, int count);
void	handle_clean_all(t_program *program, pthread_mutex_t *forks,
			int count);
void	handle_error_all_exit(t_program *program, pthread_mutex_t *forks);

// threads
int		start_threads(t_program *program, t_philosopher *philosophers);
int		setup_threads(t_program *program, t_philosopher *philosophers);

//philo_cycle
void	*philo_cycle(void *arg);
void	sleep_cycle(t_philosopher *philo);
void	think_cycle(t_philosopher *philo);
void	eat_cycle(t_philosopher *philo);

//monitor_philos
void	*monitor_philos(void *parameter);
int		check_philo_dead(t_philosopher *philo);
int		check_eat_count(t_program *program);
int		check_ttdie_philos(t_program *program);

#endif
