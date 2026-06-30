/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.h                                      :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 16:48:42 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/07 16:08:29 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "minishell.h"

// execution of redirection
int				handle_input_redirection(const char *file);
int				handle_output_redirection(const char *file);
int				handle_append_redirection(const char *file);
int				handle_heredoc_redirection(t_minishell *shell,
					char *delimiter, int should_expand);
int				apply_redirections(t_redir *redir_list);
int				process_heredocs(t_minishell *shell,
					t_command *cmd_list);
int				redirect_stdin_to_pipe(int pipe_read_fd);

//parse redirections
int				parse_single_redirection(t_minishell *shell,
					t_parser_state *state, t_command *cmd);
void			add_redirection_to_command(t_command *cmd, t_redir *redir);
t_redir_type	convert_token_to_redir_type(t_token_type token_type);

// heredoc utils
int				token_was_quoted(char *input, int token_pos, int token_len);
int				is_heredoc_end(char *line, char *delimiter);
void			heredoc_child_cleanup(t_minishell *shell);

#endif
