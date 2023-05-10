/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:24:09 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/10 16:00:43 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int args_numbers(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '1')
        {
            puts("1");
            return (1);
        }
        i++;
    }
    return (0);
}

void built_exit(t_cmds *cmds)
{
    if (args_numbers(cmds->cmd_line[1]) == 1)
    {
        printf("Comand not found");
        exit(1);
    }
    printf("exit\n");
    exit(0);
}