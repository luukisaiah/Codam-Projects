/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_redirec.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/21 16:59:20 by doda-cun      #+#    #+#                 */
/*   Updated: 2025/12/08 17:46:34 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc_eof(t_minishell *shell, char *delimiter, int pipe_fd)
{
	is_heredoc_end(NULL, delimiter);
	close(pipe_fd);
	get_next_line(-1);
	heredoc_child_cleanup(shell);
	if (g_signal_flag == SIGINT)
		exit(130);
	else
		exit(0);
}

static void	write_heredoc_line(t_minishell *shell, char *line,
	int should_expand, int pipe_fd)
{
	char	*expanded;

	if (should_expand)
	{
		expanded = expand_one_arg(shell, line, shell->env_list);
		write(pipe_fd, expanded, ft_strlen(expanded));
		free(line);
	}
	else
	{
		write(pipe_fd, line, ft_strlen(line));
		free(line);
	}
	write(pipe_fd, "\n", 1);
}

static int	read_heredoc_lines(t_minishell *shell, char *delimiter,
	int should_expand, int pipe_fd[2])
{
	char	*line;

	setup_heredoc_signals();
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			handle_heredoc_eof(shell, delimiter, pipe_fd[1]);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (is_heredoc_end(line, delimiter))
			break ;
		write_heredoc_line(shell, line, should_expand, pipe_fd[1]);
	}
	close(pipe_fd[1]);
	heredoc_child_cleanup(shell);
	exit(0);
}

int	handle_heredoc_redirection(t_minishell *shell,
	char *delimiter, int should_expand)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipe_fd) < 0)
		return (perror("pipe"), -1);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		return (setup_sig(), perror("fork"), -1);
	if (pid == 0)
		read_heredoc_lines(shell, delimiter, should_expand, pipe_fd);
	waitpid(pid, &status, 0);
	g_signal_flag = 0;
	close(pipe_fd[1]);
	setup_sig();
	if ((WIFEXITED(status) && WEXITSTATUS(status) == 130)
		|| (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT))
		return (close(pipe_fd[0]), shell->last_exit_status = 130, -1);
	return (pipe_fd[0]);
}

int	redirect_stdin_to_pipe(int pipe_read_fd)
{
	if (dup2(pipe_read_fd, STDIN_FILENO) < 0)
	{
		perror("dup2");
		close(pipe_read_fd);
		return (-1);
	}
	close(pipe_read_fd);
	return (0);
}
