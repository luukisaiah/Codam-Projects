/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untracked.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:46:56 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 12:25:44 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNTRACKED_H
# define UNTRACKED_H

# include "minishell.h"

char	**copy_string_arr(char **args);
void	free_array_untracked(char **array);
char	**env_list_to_envp_untracked(t_env *env_list);
void	free_env_untracked(t_env *env_list);

// helpers
char	*create_env_string(t_env *node);
char	**free_envp(char **envp, int i);

#endif
