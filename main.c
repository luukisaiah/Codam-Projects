/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                              :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/09 18:56:59 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 17:12:18 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal_flag;

static char	*check_prompt(void)
{
	char	*line;

	g_signal_flag = 0;
	line = readline("minishell$ ");
	if (!line)
		return (NULL);
	if (*line && !check_input_whitespace(line))
		add_history(line);
	return (line);
}

t_minishell static	*initialize_minishell(void)
{
	t_minishell	*shell;

	shell = malloc(sizeof(t_minishell));
	if (!shell)
	{
		printf("minishell: malloc initialize_shell failed\n");
		exit(EXIT_FAILURE);
	}
	shell->input = NULL;
	shell->freelist = NULL;
	shell->env_list = NULL;
	shell->lexer = NULL;
	shell->tokens = NULL;
	shell->commands = NULL;
	shell->parser_state = NULL;
	shell->exit_status = 0;
	shell->last_exit_status = g_signal_flag;
	shell->should_exit = 0;
	return (shell);
}

static void	main_loop(t_minishell *shell)
{
	while (1)
	{
		shell->input = check_prompt();
		if (shell->input == NULL)
			break ;
		if (check_input_whitespace(shell->input))
			continue ;
		shell->lexer = lexer_initialize(shell);
		shell->tokens = tokenize_input(shell);
		if (!check_token_list(shell->tokens))
		{
			free_minishell_input(shell);
			continue ;
		}
		shell->parser_state = init_parser_state(shell);
		shell->commands = parse_pipeline(shell, shell->parser_state);
		if (shell->commands)
			shell->last_exit_status = execute_pipeline(shell->commands,
					shell->env_list, shell);
		free_minishell_input(shell);
		if (shell->should_exit)
			break ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;
	int			exit_status;

	(void)argc;
	(void)argv;
	shell = initialize_minishell();
	setup_sig();
	shell->env_list = init_env_list(shell, envp);
	main_loop(shell);
	exit_status = shell->exit_status;
	cleanup_shell(shell);
	free(shell);
	exit (exit_status);
}
