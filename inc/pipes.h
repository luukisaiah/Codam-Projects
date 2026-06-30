/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:02:39 by doda-cun          #+#    #+#             */
/*   Updated: 2025/12/02 12:32:42 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "minishell.h"

int		count_commands(t_command *cmd_list);
int		**create_pipes(t_minishell *shell, int num_pipes);
void	close_all_pipes(int **pipes, int num_pipes);
void	execute_all_commands(t_minishell *shell, t_command *cmd_list,
			t_pipe_data *data);
void	execute_child(t_minishell *shell, t_command *cmd,
			t_pipe_data *data, int index);
int		wait_for_all(int *pids, int cmd_count, t_minishell *shell);
int		execute_multiple_pipes(t_command *cmd_list, t_env *env_list,
			t_minishell *shell, int cmd_count);
void	pipes_cleanup(t_minishell *shell, int **pipes, int num_pipes);
int		clean_and_exit(t_minishell *shell, int exit_code);
void	execute_child_free_exit(t_minishell *shell, int exit_code);
int		builtin_exit_in_pipe(t_minishell *shell, char **args);

#endif
