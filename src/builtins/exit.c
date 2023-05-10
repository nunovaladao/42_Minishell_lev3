/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:24:09 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/10 21:15:44 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int args_numbers(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '-' || str[i] == '+')
            i++;
        if (!ft_isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}

void built_exit(t_cmds *cmds)
{
    int nb_args;
    
    nb_args = nb_of_args(cmds);
    printf("exit\n");
    if (nb_args == 2)
    {
        if (args_numbers(cmds->cmd_line[1]) == 1)
        {
            printf("bash: exit: %s: numeric argument required\n", cmds->cmd_line[1]);
            exit(1);
        }
    }
    exit(0);
}