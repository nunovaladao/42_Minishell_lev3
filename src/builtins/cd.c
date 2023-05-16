/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:07:46 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/16 23:22:54 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int built_cd(t_cmds *cmds)
{
    cmds->new_dir = cmds->cmd_line[1];
    if (nb_of_args(cmds) <= 2)
    {
        if (cmds->new_dir == NULL)
            cmds->new_dir = getenv("HOME");
        else if (ft_strcmp(cmds->new_dir, "~"))
            cmds->new_dir = getenv("HOME");
        chdir(cmds->new_dir);
    }
    else
    {
        printf("minishell: cd: too many arguments\n");
        return (g_ex_status = 2);
    }
    return (g_ex_status = 0);
}