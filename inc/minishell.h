/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:47:05 by doda-cun          #+#    #+#             */
/*   Updated: 2025/11/09 11:54:58 by doda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>

# include "libft.h"
# include "typedef.h"

# include "environment.h"
# include "list.h"
# include "lexer.h"
# include "token.h"
# include "tokenizer.h"
# include "utils.h"
# include "builtins.h"
# include "signals.h"
# include "pipes.h"
# include "parser.h"
# include "execute.h"
# include "builtins.h"
# include "expanding_dollarsign.h"
# include "redirections.h"
# include "untracked.h"

# include <readline/readline.h> // lets you show prompt and get user input
# include <readline/history.h> // saves each command (to use up arrow later)

#endif
