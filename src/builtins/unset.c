/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:34:14 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/15 20:12:36 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int built_unset(t_cmds *cmds, t_shell *shell)
{
    int i;

    i = 0;
    if (nb_of_args(cmds) > 1)
        while (cmds->cmd_line[++i])
            remv_var_env(cmds->cmd_line[i], shell);
    return (0);
}