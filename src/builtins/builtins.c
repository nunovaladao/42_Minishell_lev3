/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:36:22 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/10 14:34:08 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int builtins(t_cmds *cmds)
{
    if (ft_strcmp(cmds->cmd_line[0], "echo") == 0)
        built_echo(cmds);
    else if (ft_strcmp(cmds->cmd_line[0], "clear") == 0 || ft_strcmp(cmds->cmd_line[0], "x") == 0)
        clear_screen(cmds);
    else if (ft_strcmp(cmds->cmd_line[0], "cd") == 0)
        built_cd(cmds);
    else if (ft_strcmp(cmds->cmd_line[0], "pwd") == 0)
        built_pwd();
    else if (ft_strcmp(cmds->cmd_line[0], "exit") == 0)
        built_exit();
    else
        return (-1);
    return (0);
}