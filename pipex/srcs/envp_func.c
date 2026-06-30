/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp_func.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 15:29:22 by lderks        #+#    #+#                 */
/*   Updated: 2025/10/20 15:47:41 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

char	*get_path(char *envp[])
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*find_command(char *command, char **all_paths)
{
	char	*full_path;
	int		i;
	size_t	path_size;

	i = 0;
	while (all_paths[i])
	{
		full_path = malloc(ft_strlen(all_paths[i]) + ft_strlen(command) + 2);
		if (!full_path)
			return (NULL);
		path_size = ft_strlen(all_paths[i]) + ft_strlen(command) + 2;
		ft_strlcpy(full_path, all_paths[i], path_size);
		ft_strlcat(full_path, "/", path_size);
		ft_strlcat(full_path, command, path_size);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free (full_path);
		i++;
	}
	return (NULL);
}

char	*process_envp_path(char *cmd_name, char *envp[])
{
	char	*path_str;
	char	**all_paths;
	char	*cmd_path;

	path_str = get_path(envp);
	if (!path_str)
		error_exit(0);
	all_paths = ft_split(path_str, ':');
	if (!all_paths)
		error_exit(0);
	cmd_path = find_command(cmd_name, all_paths);
	if (!cmd_path)
	{
		if (access(cmd_name, F_OK | X_OK) == 0)
		{
			free_array(all_paths);
			return (ft_strdup(cmd_name));
		}
	}
	free_array(all_paths);
	return (cmd_path);
}
