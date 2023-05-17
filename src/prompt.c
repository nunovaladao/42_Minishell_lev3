/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:57:00 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/17 11:43:16 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int g_ex_status;

char *show_prompt()
{
    char *line;
    char *str;
    
    line = readline("minishell$ ");
    if (!line)
    {
        printf("exit\n");
        clear_history();
        free(line);
        exit(g_ex_status = 0);
    }
    str = ft_strtrim(line, " \t");
    if (*str == '\0')
    {
        free(str);
        str = NULL;
    }
    free(line);
    return (str);
}
