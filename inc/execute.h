/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:07:10 by lderks            #+#    #+#             */
/*   Updated: 2025/11/11 13:04:54 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

int		exec_external_with_redir(t_command *cmd,
			t_env *env_list, t_minishell *shell);
int		exec_builtin_with_redir(t_command *cmd,
			t_env *env_list, t_minishell *shell);
int		exec_command_with_redir(t_command *cmd,
			t_env *env_list, t_minishell *shell);
int		exec_builtin_in_parent_with_redir(t_command *cmd,
			t_env *env_list, t_minishell *shell);
int		exec_external(char **args, t_env *env_list, t_minishell *shell);
int		exec_command(char **args, t_env *env_list, t_minishell *shell);
int		handle_no_path(char **envp, char **args_copy, char *cmd);

int		execute_ext_command(t_minishell *shell, char **args, t_env *env_list);
int		execute_pipeline(t_command *cmd_list,
			t_env *env_list, t_minishell *shell);
int		try_exec_path(t_minishell *shell, char *dir,
			char **args, char **envp);
int		handle_parent_wait(t_minishell *shell,
			char**args, int status);

//redirection commands exec
int		try_dirs_and_exec(t_minishell *shell, char **dir,
			char **args, t_exec_ctx *ctx);
int		safe_fork_builtin(char *cmd);
int		save_file_descriptor(int *saved_fds);
void	restore_fds(int *saved_fds);

#endif
