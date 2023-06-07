/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:40:36 by nsoares-          #+#    #+#             */
/*   Updated: 2023/06/07 14:07:11 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int exec_cmd_line(t_shell *shell, t_cmds *cmds)
{
    cmds->path = search_path(shell, cmds);
    if (cmds->path != NULL)
    {
        execve(cmds->path, cmds->cmd_line, shell->envp);
        exit(EXIT_FAILURE);
    }
    else
        printf("minishell: command not found: %s\n", cmds->cmd_line[0]);
    return 0;
}
