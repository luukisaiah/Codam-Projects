/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 14:59:09 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 17:06:22 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

//  _safe_
void	*safe_malloc(t_minishell *mini, size_t size);
void	safe_free(t_minishell *shell, void **ptr);
char	*strdup_safe(t_minishell *mini, const char *str);
char	*strjoin_safe(t_minishell *shell, char const *s1, char const *s2);
char	*substr_safe(t_minishell *shell, char const *s,
			unsigned int start, size_t len);
char	**split_safe(t_minishell *shell, char const *s, char c);

// _free_
void	free_split(char **arr);
void	free_env_list(t_minishell *shell, t_env *env);
void	free_lexer(t_minishell *shell, t_lexer *lexer);
void	free_token_list(t_minishell *shell, void *content);
void	free_command_structure(t_minishell *shell, t_command *commands);
void	free_minishell_input(t_minishell *shell);
void	free_minishell(t_minishell *shell);
void	free_array(t_minishell *shell, char **array);
void	free_tokenizer(t_minishell *shell, t_tokenizer *tracker);
void	free_segment_list(t_minishell *shell, void *content);
void	cleanup_shell(t_minishell *shell);
void	free_remaining_in_freelist(t_minishell *shell);

// _check_ / _error_
void	check_malloc(t_minishell *mini, void *ptr);
void	cleanup_and_exit(t_minishell *mini);
int		check_input_whitespace(char *input);
t_token	*get_token_from_list(t_list *list);
int		check_token_list(t_list *token_list);

// _normal_utils_
void	error_message(char *function, char *message);
int		ft_intcheck_print(int c);
int		ft_isspace(const char c);
int		ft_isredirect(const char c);

#endif
