/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/01/10 17:01:40 by lderks         #+#    #+#                */
/*   Updated: 2025/02/11 13:19:10 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

char	*process_envp_path(char *cmd1, char *envp[]);
int		is_empty_str(const char *str);
void	error_exit(int message);
void	command_not_found(char *command);
void	free_array(char **array);
void	extra_check_file(char *argv);
int		ft_isspace(int c);
int		handle_quotes(char c, int in_quotes, char *quote_char);
int		is_quote(char c);
void	initialize_everything(int *t_count, int *i, int *now_t, char *cmd);
int		count_tokens(char *cmd);
char	**pipex_split(char *cmd);
void	pipex(int argc, char **argv, char *envp[]);

#endif
