/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_dollarsign.h                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:57:32 by doda-cun          #+#    #+#             */
/*   Updated: 2025/12/02 20:07:56 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDING_DOLLARSIGN_H
# define EXPANDING_DOLLARSIGN_H

# include "minishell.h"

char	**expand_variables(t_minishell *mini, char **args, t_env *env_list);
char	*extract_varname(t_minishell *mini, const char *s, int *i);
char	*expand_one_arg(t_minishell *mini, char *arg, t_env *env_list);
char	*handle_dollar_expansion(t_minishell *shell, char *arg,
			int *i, t_env *env_list);
char	*expand_tilde(char *path, t_env *env_list, t_minishell *shell);

#endif
