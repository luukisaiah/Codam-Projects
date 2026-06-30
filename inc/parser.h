/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/06 18:00:26 by doda-cun      #+#    #+#                 */
/*   Updated: 2026/04/13 17:00:37 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"


t_token			*get_current_token(t_parser_state *state);
void			advance_to_next_token(t_parser_state *state);
void			add_arg(t_minishell *shell, t_command *cmd, char *word);
int				process_word_token(t_minishell *shell, t_parser_state *state,
					t_command *cmd);
int				is_command_end_token(t_token_type type);
int				is_word_token(t_token_type type);
int				is_redirection_token(t_token_type type);
t_token			*get_current_token(t_parser_state *state);
void			advance_to_next_token(t_parser_state *state);
t_command		*init_command(t_minishell *shell);
void			free_command(t_minishell *shell, t_command *cmd);
t_command		*parse_simple_command(t_minishell *shell,
					t_parser_state *state);
void			free_redir_list(t_minishell *shell, t_redir *redir_list);
void			free_args_array(t_minishell *shell, char **args);
void			close_command_fds(t_command *cmd);
int				handle_parse_error_cmd(t_minishell *shell,
					t_parser_state *state, t_command *cmd);
t_command		*parse_pipeline(t_minishell *shell, t_parser_state *state);
void			free_command_pipeline(t_minishell *shell, t_command *pipeline);
int				handle_logical_op_error(t_minishell *shell,
					t_token *token, t_command *pipeline);
char			**expand_args(char **args, t_env *env_list, t_minishell *shell);
t_parser_state	*init_parser_state(t_minishell *shell);

#endif
