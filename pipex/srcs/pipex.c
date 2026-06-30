/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                             :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/12 15:34:15 by lderks        #+#    #+#                 */
/*   Updated: 2025/02/11 13:18:35 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

int	open_check_file(char *file, int child_or_parent)
{
	int	open_fd;

	if (child_or_parent == 0)
	{
		extra_check_file(file);
		open_fd = open(file, O_RDONLY);
	}
	else
	{
		open_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (open_fd == -1)
		{
			perror("Error: permission denied");
			exit(EXIT_FAILURE);
		}
	}
	return (open_fd);
}

void	executioner(char argv[], char **envp)
{
	char	*cmd_path;
	char	**split_cmd;

	cmd_path = process_envp_path(argv, envp);
	split_cmd = pipex_split(argv);
	if (!split_cmd)
		error_exit(0);
	cmd_path = process_envp_path(split_cmd[0], envp);
	if (!cmd_path)
	{
		free_array(split_cmd);
		command_not_found(argv);
	}
	if (execve(cmd_path, split_cmd, envp) == -1)
	{
		free(cmd_path);
		free_array(split_cmd);
		command_not_found(argv);
	}
}

void	child(char **argv, int *pipe_fd, char **envp)
{
	int	inputfile_fd;

	inputfile_fd = open_check_file(argv[1], 0);
	close(pipe_fd[0]);
	if (dup2(inputfile_fd, STDIN_FILENO) == -1)
	{
		perror("Error dup2 child inputfile");
		exit(EXIT_FAILURE);
	}
	close(inputfile_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error dup2 child");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	executioner(argv[2], envp);
}

void	parent(char **argv, int *pipe_fd, char **envp)
{
	int	outputfile_fd;

	outputfile_fd = open_check_file(argv[4], 1);
	if (outputfile_fd == -1)
		error_exit(0);
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("Error dup2 parent");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	if (dup2(outputfile_fd, STDOUT_FILENO) == -1)
	{
		perror("Error dup2 parent outputfile");
		exit(EXIT_FAILURE);
	}
	close(outputfile_fd);
	executioner(argv[3], envp);
}

int	main(int argc, char **argv, char *envp[])
{
	int		pipe_fd[2];
	pid_t	process_id;

	if (argc != 5)
		error_exit(1);
	extra_check_file(argv[1]);
	if (is_empty_str(argv[2]) == 1 || is_empty_str(argv[3]) == 1)
	{
		ft_putstr_fd("Error: Empty command\n", 2);
		exit (EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1)
		error_exit(0);
	process_id = fork();
	if (process_id == -1)
		error_exit(0);
	if (process_id == 0)
		child(argv, pipe_fd, envp);
	else
	{
		parent(argv, pipe_fd, envp);
		waitpid(process_id, NULL, 0);
	}
}
