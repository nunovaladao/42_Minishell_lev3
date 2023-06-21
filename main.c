/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:12:57 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/09 13:22:50 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int  g_ex_status;

int is_operator(char c)
{
	if (c == 60) 		// <
		return (1);
	if (c == 62)		// >
		return (1);
	if (c == 124) 		// |
		return (1);
	return (0);
}

// Se WIFSIGNALED(wstatus) for verdadeiro, significa que o processo filho foi realmente encerrado por um sinal. Nesses casos, a linha wstatus += 128; adiciona 128 ao valor do status. Isso é feito para garantir que o status de saída do processo encerrado seja distinguível de um status de saída normal (que normalmente varia de 0 a 255).

// O valor 128 é adicionado porque historicamente, quando um processo é encerrado por um sinal, o shell retorna um status de saída que é a soma de 128 e o número do sinal.

// O valor 130 é significativo porque, em sistemas Unix-like, é o código de status retornado quando um processo é interrompido por um sinal SIGINT, que é o sinal enviado quando o usuário pressiona Ctrl+C no terminal.

// Portanto, essa linha verifica se o processo filho foi interrompido por um sinal SIGINT, e se for o caso, imprime uma nova linha ('\n') no descritor de arquivo de saída padrão (STDOUT_FILENO). Isso é comum em terminais para exibir uma nova linha após a interrupção de um comando pelo usuário.

void	ft_wait(t_shell *sh)
{
	int	wstatus;

	if (waitpid(sh->pid, &wstatus, 0) != -1)
	{
		if (WIFSIGNALED(wstatus))
			wstatus += 128;
		if (sh->fork)
			g_ex_status = wstatus;
		if (g_ex_status == 130)
			ft_putchar_fd('\n', STDOUT_FILENO);
		sh->proc--;
	}
	while (sh->proc)
	{
		wait(0);
		sh->proc--;
	}
	if (g_ex_status > 255)
		g_ex_status = g_ex_status / 255;
}


int operators(t_shell *sh)
{
    t_token	*start;

	start = NULL;
	start = sh->head_token;
	while (start)
	{
		if (start->type == 'O')
		{
			if (ft_strcmp(start->word, "|") == 0)
			{
				if (start->next == NULL || start->prev == NULL || start->next->type == 'O')
				{
					g_ex_status = 2;
					printf("minishell: syntax error near unexpected token '%s'\n",
						start->word);
					return (1);
				}
			}
			else if (ft_strcmp(start->word, "<") == 0 || ft_strcmp(start->word, ">") == 0 || ft_strcmp(start->word, ">>") == 0) 
			{
				if (start->next == NULL)
				{
					g_ex_status = 2;
					printf("minishell: syntax error near unexpected token `newline\'\n");
					return (1);
				}
				if (start->next->type == 'O')
				{
					g_ex_status = 2;
					printf("minishell: syntax error near unexpected token '%s'\n",
						start->word);
					return (1);
				}
			}
			else if (start->prev == NULL && ft_strcmp(start->word, "<<") == 0)
			{
				g_ex_status = 2;
				printf("minishell: syntax error near unexpected token '%s'\n",
					start->word);
				return (1);
			}
		}
		start = start->next;
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
    t_shell shell;
    
    init(ac, av, envp, &shell);
    while (1)
    {
        signals();
        shell.cmd_line = show_prompt(&shell);
        if (!shell.cmd_line)
           continue;
        add_history(shell.cmd_line);
        if (!words(&shell))
			execCmd(&shell);
		ft_wait(&shell);
        free(shell.cmd_line);
		free_listtoken(shell.head_token);
		free_listcmd(shell.cmds);
        shell.head_token = NULL;
		shell.cmds = NULL;
    }
    free_all(&shell);
    return (0);
}
