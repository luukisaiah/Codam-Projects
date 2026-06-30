/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:17:22 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 11:54:15 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "typedef.h"

void			tokenizer_dq_state(t_lexer *lexer, t_tokenizer *tracker);
void			tokenizer_normal_state(t_lexer *lexer, t_tokenizer *tracker);
void			tokenizer_sq_state(t_lexer *lexer, t_tokenizer *tracker);
void			tokenizer_check_state(t_minishell *shell, t_lexer *lexer,
					t_tokenizer *tracker);
char			*extract_word_dq(t_minishell *shell, t_lexer *lexer,
					t_token_segment *segment);
char			*extract_word_normal(t_minishell *shell, t_lexer *lexer,
					t_token_segment *segment);
char			*extract_word_sq(t_minishell *shell, t_lexer *lexer,
					t_token_segment *segment);
t_token			*extract_word_token(t_minishell *shell, t_lexer *lexer,
					t_tokenizer *tracker);
void			tokenizer_first_state(t_lexer *lexer, t_tokenizer *tracker);
t_token_segment	*init_segment(t_minishell *shell, t_lexer *lexer,
					t_tokenizer *tracker);
t_tokenizer		*tokenizer_init(t_minishell *shell, t_lexer *lexer);

#endif
