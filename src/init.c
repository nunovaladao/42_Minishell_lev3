/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:28:59 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/16 13:56:24 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void init(int ac, char **av, char **envp, t_shell *sh)
{
    (void)ac;
    (void)av;
    g_ex_status = 0;
    sh->cmd_line = NULL;
	sh->cmds = NULL;
	sh->envp = mtr_dup(envp);
	sh->pid = 0;
}