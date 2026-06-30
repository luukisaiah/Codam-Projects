/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/11 12:24:54 by lderks         #+#    #+#                */
/*   Updated: 2025/04/14 15:36:27 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libft/incl/libft.h"

typedef struct struct_node
{
	int					value;
	int					index;
	struct struct_node	*next;
}	t_node;

typedef struct struct_stack
{
	t_node	*first_node;
	int		size;
}	t_stack;

void	small_or_big_stack(t_stack *stack_a, t_stack *stack_b);
void	algorithm(t_stack *stack_a, t_stack *stack_b);
void	concat_args(int argc, char **argv, char **s, size_t len);
void	free_array(char **numbers);
void	free_stacks(t_stack *a, t_stack *b);
void	initialize_stack(t_stack *stack_a, char **numbers);
void	create_index(t_stack *stack_a);
int		check_str(char *str);
int		check_double(char **numbers);
void	exit_ps(int msg);
void	push(t_stack *a, t_stack *b, char c);
void	swap(t_stack *a_stack, t_stack *b_stack, char c);
void	rotate(t_stack *a, t_stack *b, char c);
void	reverse_rotate(t_stack *a, t_stack *b, char c);
int		sorted_stack(t_stack *stack_a);
int		stack_len(t_stack *stack_a);
void	small_sorting(t_stack *stack_a, t_stack *stack_b);
int		get_value_position(t_stack *stack_a, int position);
void	small_sort(t_stack *stack_a, t_stack *stack_b);
void	five_sort(t_stack *stack_a, t_stack *stack_b);

#endif
