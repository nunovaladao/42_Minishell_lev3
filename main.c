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

/*Podem existir mais condições de erro*/
int operators(t_shell *sh)
{
    t_token	*start;

	start = NULL;
	start = sh->head_token;
	while (start)
	{
		if (start->type == 'O')
		{
			if (start->prev == NULL || start->next->type == 'O')
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
    t_cmds cmds;
    
    init(ac, av, envp, &shell);
    while (1)
    {
        signals();
        shell.cmd_line = show_prompt();
        if (!shell.cmd_line)
            continue ;
        add_history(shell.cmd_line);
        //if (div_input(&shell))
            // falta o erro ou exit
        //if (operators(&shell))
            // falta erro ou exit
        cmds.cmd_line = ft_split(shell.cmd_line, ' ');
        builtins(&cmds, &shell);
    }
    return (0);
}
