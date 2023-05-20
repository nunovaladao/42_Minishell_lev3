/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:07:59 by nmoreira          #+#    #+#             */
/*   Updated: 2023/05/14 20:07:59 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int check_quotes(t_shell *shell)
{
	if (shell->cmd_line[shell->i] == 34)
	{
		shell->i++;
		while (shell->cmd_line[shell->i] != 34)
		{
			if (shell->cmd_line[shell->i] == '\0')
				return (error_quotes('\"'));
			shell->i++;
		}
	}
	if (shell->cmd_line[shell->i] == 39)
	{
		shell->i++;
		while (shell->cmd_line[shell->i] != 39)
		{
			if (shell->cmd_line[shell->i] == '\0')
				return (error_quotes('\''));
			shell->i++;
		}
	}
	return (0);
}

void lexer_op(t_shell *shell)
{
	if (shell->i - shell->wd_lim)
		node(shell, ft_substr(shell->cmd_line, shell->wd_lim, (shell->i - shell->wd_lim))); // se tivermos o operador junto das palavras sem espaços
	shell->wd_lim = shell->i;
	if (shell->cmd_line[shell->i] == 60 || shell->cmd_line[shell->i] == 62)
	{
		if (shell->cmd_line[shell->i + 1] && shell->cmd_line[shell->i] == shell->cmd_line[shell->i + 1])
			shell->i += 2;
		else
			shell->i++;
	}
	else
		shell->i++;
	if (shell->i - shell->wd_lim)
		node(shell, ft_substr(shell->cmd_line, shell->wd_lim, (shell->i - shell->wd_lim)));
	node_type(shell, 'O');
}

void lexer_word(t_shell *shell)
{
	if (shell->i - shell->wd_lim)
		node(shell, ft_substr(shell->cmd_line, shell->wd_lim, (shell->i - shell->wd_lim)));
	while (shell->cmd_line[shell->i] == ' ')
		shell->i++;
	shell->wd_lim = shell->i;
}

int div_input(t_shell *shell)
{
	shell->i = 0;
	shell->wd_lim = 0;
	while (shell->cmd_line[shell->i] == '\0')
	{
		if (shell->cmd_line[shell->i] == '\'' || shell->cmd_line[shell->i] == '\"')
		{
			if (check_quotes(shell))
			{
				g_ex_status = 2;
				return (1);
			}
		}
		else if (is_operator(shell->cmd_line[shell->i]))
			lexer_op(shell);
		else if (shell->cmd_line[shell->i] == ' ')
			lexer_word(shell);
		else
			shell->i++;
	}
	return (0);
}