/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:36:22 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/15 20:06:51 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int builtins(t_cmds *cmds, t_shell *shell)
{
    if (ft_strcmp(cmds->cmd_line[0], "echo") == 0)
        built_echo(cmds);
    else if (ft_strcmp(cmds->cmd_line[0], "x") == 0)
        clear_screen(cmds);
    else if (ft_strcmp(cmds->cmd_line[0], "cd") == 0)
        built_cd(cmds);
    else if (ft_strcmp(cmds->cmd_line[0], "pwd") == 0)
        built_pwd();
    else if (ft_strcmp(cmds->cmd_line[0], "env") == 0)
        built_env(shell);
    else if (ft_strcmp(cmds->cmd_line[0], "export") == 0)
        built_export(shell, cmds);
    else if (ft_strcmp(cmds->cmd_line[0], "unset") == 0)
        built_unset(cmds, shell);
    else if (ft_strcmp(cmds->cmd_line[0], "exit") == 0)
    {
        if (nb_of_args(cmds) > 2 && args_numbers(cmds->cmd_line[1]) == 0)
        {
            printf("bash: exit: too many arguments\n");
            return (0);
        }
        built_exit(cmds);
    }
    else
        return (-1);
    return (0);
}