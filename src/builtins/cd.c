/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:07:46 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/09 15:34:15 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int built_cd(t_cmds *cmds)
{
    cmds->new_dir = cmds->cmd_line[1];

    if (cmds->new_dir == NULL)
        cmds->new_dir = getenv("HOME");
    chdir(cmds->new_dir);
    return 0;
}