/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:31:20 by nsoares-          #+#    #+#             */
/*   Updated: 2023/07/11 11:12:55 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ex_status;

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_ex_status = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("Quit: (core dumped)\n");
		kill(0, SIGINT);
		g_ex_status = 131;
	}
}

void	signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
