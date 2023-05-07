/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:57:00 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/07 22:30:11 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char show_prompt(t_shell *cmd)
{
    cmd->line = readline("minishell$ ");
    cmd->str = ft_strtrim(cmd->line, " \t");
    
    if (cmd->str == NULL)
    {
        free(cmd->str);
        cmd->str = NULL;
    }
    free(cmd->line);
    return (*cmd->str);
}