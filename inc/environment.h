/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:57:45 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 11:55:11 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

t_env	*new_env_node(t_minishell *shell, char *name, char *value);
void	add_env_node(t_env **head, t_env *node_toadd);
t_env	*init_env_list(t_minishell *shell, char **environment);
void	var_assig(t_minishell *shell, char *args, t_env *env_list);
t_env	*find_env(t_env *env_list, char *name);
void	print_sorted_env(t_minishell *shell, t_env *head);
void	sort_env_arr(t_env **env_arr, int size);
t_env	**env_list_to_array(t_minishell *shell, t_env *head, int *size);
int		valid_identifiers(char *str);
void	free_env_node(t_minishell *shell, t_env *node);
void	remove_env_var(t_minishell *shell, t_env *env_list, char *name);
int		env_list_size(t_env *head);
char	**env_list_to_envp(t_minishell *shell, t_env *head);
char	*get_env_value(t_minishell *shell, t_env *env_list, char *var_name);
char	*expand_variable_token(char *token, t_env *env_list);
void	expand_command_args(t_minishell *shell, char **argv, t_env *env_list);
int		handle_env_with_arg(char **args, t_env *env_list, t_minishell *shell);
char	*join_path(t_minishell *shell, char *dir, char *cmd);
int		search_n_exec(t_minishell *shell, char **args, t_env *env_list);
void	set_env_value(t_minishell *shell, t_env *env_list,
			char *name, char *value);

#endif
