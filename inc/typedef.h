/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:32:45 by lderks            #+#    #+#             */
/*   Updated: 2025/11/10 18:34:17 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include <fcntl.h>

typedef struct s_exec_ctx
{
	char	**envp;
	char	**args_copy;
}	t_exec_ctx;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*file;
	int				fd;
	struct s_redir	*next;
	int				should_expand;
}	t_redir;

typedef struct s_lexer
{
	int		cur_pos;
	int		next_pos;
	char	*input;
	char	cur_char;
}	t_lexer;

typedef enum e_token_type
{
	T_REDIRECT_IN,
	T_REDIRECT_OUT,
	T_APPEND_TO,
	T_HERE_DOCUMENTS,
	T_AND,
	T_PIPE,
	T_OR,
	T_WORD,
	T_EOF,
	T_ERROR
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	int				pos;
}	t_token;

typedef enum e_token_state
{
	T_NORMAL_STATE,
	T_SQOUTE_STATE,
	T_DQUOTE_STATE
}	t_token_state;

typedef enum e_token_action
{
	T_CONTINUE,
	T_END_WORD,
	T_ERROR_A
}	t_token_action;

typedef struct s_token_segment
{
	t_token_state	state;
	int				start_pos;
	int				end_pos;
}	t_token_segment;

typedef struct s_tokenizer
{
	t_token_state	prev_state;
	t_token_state	state;
	t_token_state	next_state;
	t_token_action	action;
	t_list			*segments;
	t_token_segment	*cur_segment;
	int				token_start;
	int				token_end;
	char			*error_msg;
}	t_tokenizer;

typedef struct s_command
{
	char				**args;
	int					exit_status;
	int					pid;
	t_redir				*redir_list;
	int					fd_input;
	int					fd_output;
	int					last_heredoc_fd;
	struct s_command	*next;
}	t_command;

typedef enum e_job_state
{
	RUNNING,
	STOPPED,
	DONE
}	t_job_state;

typedef struct s_job
{
	int				job_id;
	pid_t			*pid_list;
	char			*command;
	t_job_state		status;
	struct s_job	*next;
}	t_job;

typedef struct s_parser_state
{
	t_list	*current_token;
	int		has_error;
}	t_parser_state;

typedef struct s_pipe_data
{
	t_env	*env_list;
	int		last_exit_status;
	int		**pipes;
	int		*pids;
	int		num_pipes;
	int		num_cmds;
}	t_pipe_data;

typedef struct s_minishell
{
	char			*input;
	t_lexer			*lexer;
	t_list			*tokens;
	t_command		*commands;
	t_list			*freelist;
	t_env			*env_list;
	t_parser_state	*parser_state;
	int				exit_status;
	int				last_exit_status;
	int				should_exit;
}	t_minishell;

#endif
