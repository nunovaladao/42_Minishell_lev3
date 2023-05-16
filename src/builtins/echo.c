/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:57:50 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/16 15:47:10 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void echo_env(t_shell *shell, t_cmds *cmds)
{
    int i = 0;
    int pos;

    while (cmds->cmd_line[++i])
    {
        if (pos_char(cmds->cmd_line[i], '$') == 0)
        {
            char *var_name = cmds->cmd_line[i] + 1; // Ignorar o caractere '$'
            pos = pos_envp(var_name, shell->envp);
            if (pos >= 0)
            {
                char *value = ft_strchr(shell->envp[pos], '='); // Encontrar o caractere '='
                if (value != NULL)
                    printf("%s ", value + 1); // Imprimir a parte após o caractere '='
            }
        }  
    }
}

int built_echo(t_cmds *cmds)
{
    int i;
    int n_flag;

    n_flag = 0;
    i = 1;
    while (cmds->cmd_line[i] != NULL && ft_strcmp(cmds->cmd_line[i], "-n") == 0) 
    {
        n_flag = 1;
        i++;
    }
    if (cmds->cmd_line[i] != NULL)
    {
        printf("%s", cmds->cmd_line[i]);
        i++;
    }
    while (cmds->cmd_line[i] != NULL)
    {
        printf(" %s", cmds->cmd_line[i]);
        i++;
    }
    if (n_flag == 0)
        printf("\n");
    return (g_ex_status = 0);
}
