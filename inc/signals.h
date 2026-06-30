/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: doda-cun <doda-cun@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:03:43 by doda-cun          #+#    #+#             */
/*   Updated: 2025/12/02 19:43:51 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

extern volatile sig_atomic_t	g_signal_flag;
void							sigint_handler(int sig);
void							setup_sig(void);
void							sig_restore(void);
void							handle_stopped(int status, char **args);
void							handle_kill(int status);
void							handle_exit(int status);
void							handle_heredoc_sigint(int sig);
void							setup_heredoc_signals(void);
void							restore_default_signals(void);

#endif
