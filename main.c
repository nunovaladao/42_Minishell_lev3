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

// Data: 07/06/23 Hora: 15h
// Atualizado: melhoramento na built-in (cd) e adicionamento dos redirects.

#include "minishell.h"

int  g_ex_status;

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
        //if (check_input(&shell) == 0)
            // exec
        cmds.cmd_line = ft_split(shell.cmd_line, ' ');
        check_redir(&cmds);
        builtins(&cmds, &shell);
        exec_cmd_line(&shell, &cmds);
    }
    return (0);
}
