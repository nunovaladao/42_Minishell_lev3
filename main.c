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

int main(int ac, char **av)
{
    t_shell shell;
    t_cmds cmds;
    
    init(ac, av);
    while (1)
    {
        signals();
        shell.cmd_line = show_prompt();
        if (shell.cmd_line != NULL)
        {
            add_history(shell.cmd_line);
            cmds.cmd_line = ft_split(shell.cmd_line, ' ');
            builtins(&cmds);
        }
    }
    return (0);
}