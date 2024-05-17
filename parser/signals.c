/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:19:36 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/17 13:57:36 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quit_handler(int sig)
{
	(void)sig;
	printf("Quit: 3\n");
	g_sig = 131;
}

void	int_handler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
	g_sig = 1;
}

void	int_exe_sig(int sig)
{
	(void)sig;
	printf("\n");
	g_sig = 1;
}

void	int_heredoc(int sig)
{
	(void)sig;
	printf("\n");
	g_sig = 1;
}

void	set_echoctl(int fd, int enable)
{
	struct termios	term;

	tcgetattr(fd, &term);
	if (enable)
		term.c_lflag |= ECHOCTL;
	else
		term.c_lflag &= ~ECHOCTL;
	tcsetattr(fd, TCSANOW, &term);
}
