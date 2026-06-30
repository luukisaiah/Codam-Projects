/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                          :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 17:55:59 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/02 20:03:43 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		is_builtin(char *cmd);
int		exec_built_ins(char **args, t_env *env_list, t_minishell *shell);
int		builtin_echo(char **args);
int		builtin_pwd(void);
void	update_pwd(t_minishell *shell, t_env *env_list);
int		builtin_cd(char **args, t_env *env_list, t_minishell *shell);
char	*handle_cd_minus(t_minishell *shell, t_env *env_list);
char	*handle_tilde_path(char *arg, t_env *env_list,
			int *need_free, t_minishell *shell);
int		builtin_export(t_minishell *mini, char **args, t_env *env_list);
int		builtin_unset(t_minishell *shell, char **args, t_env *env_list);
int		builtin_env(t_env *env_list);
int		builtin_exit(t_minishell *shell, char **args);
int		is_numeric(char *args);
#endif
