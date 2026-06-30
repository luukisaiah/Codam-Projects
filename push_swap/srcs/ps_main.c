/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                           :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/14 16:10:52 by lderks        #+#    #+#                 */
/*   Updated: 2025/12/09 16:53:31 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int static	malloc_stacks(t_stack **stack_a, t_stack **stack_b, char ***num)
{
	(*stack_a) = NULL;
	(*stack_b) = NULL;
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		free_array(*num);
		free_stacks(*stack_a, *stack_b);
		return (1);
	}
	(*stack_a)->first_node = NULL;
	(*stack_a)->size = 0;
	(*stack_b)->first_node = NULL;
	(*stack_b)->size = 0;
	return (0);
}

void	exit_ps(int msg)
{
	if (msg == 1)
	{
		ft_putstr_fd("Error\n./push_swap <numbers>\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (msg == 2)
	{
		ft_putstr_fd("Error\n32-bit int, +/- & ' ' allowed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (msg == 3)
	{
		ft_putstr_fd("Error\nNo repetition in digits allowed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (msg == 4)
		exit(EXIT_FAILURE);
}

char static	*check_argc(int argc, char **argv, char **s)
{
	int		i;
	size_t	len;

	*s = NULL;
	i = 1;
	if (argc == 1)
		exit_ps(4);
	else if (argc == 2 && !argv[1][0])
		exit_ps(4);
	else if (argc == 2)
		*s = ft_strdup(argv[1]);
	else
	{
		len = 0;
		while (i < argc)
			len += ft_strlen(argv[i++]) + 1;
		i = 1;
		*s = malloc(sizeof(char) * len);
		if (!(*s))
			exit_ps(1);
		concat_args(argc, argv, s, len);
	}
	return (*s);
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = stack_len(stack_a);
	if (len <= 1)
		return ;
	else if (len == 2)
		swap(stack_a, stack_b, 'a');
	else
		small_sorting(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**numbers;
	char	*str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_argc(argc, argv, &str);
	if (check_str(str) == 1)
	{
		free(str);
		exit_ps(2);
	}
	numbers = ft_split(str, ' ');
	free(str);
	if (check_double(numbers) == 1)
		exit_ps(3);
	if ((malloc_stacks(&stack_a, &stack_b, &numbers)) == 1)
		exit_ps(1);
	initialize_stack(stack_a, numbers);
	create_index(stack_a);
	small_or_big_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
