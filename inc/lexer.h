/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/23 15:05:30 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 20:28:00 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "typedef.h"

t_token		*get_next_token(t_minishell *shell, t_lexer *lexer);
t_lexer		*lexer_initialize(t_minishell *shell);
void		next_char(t_lexer *lexer);
t_list		*tokenize_input(t_minishell *shell);

#endif
