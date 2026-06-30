/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:56:42 by lderks            #+#    #+#             */
/*   Updated: 2025/11/09 11:54:17 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "typedef.h"

t_token			*token_word(t_minishell *shell, t_lexer *lexer);
t_token			*token_redirects(t_minishell *shell, t_lexer *lexer);
t_token			*token_new(t_minishell *shell, t_token_type type,
					char *content);
t_token_type	token_give_redirect_type(char c, char second_c);

#endif
