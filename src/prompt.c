/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:57:00 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/08 16:04:00 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *show_prompt()
{
    char *line;
    char *str;
    
    line = readline("minishell$ ");
    if (!line)
    {
        printf("exit\n");
        free(line);
        exit(0);
    }
    if (ft_strcmp(line, "exit") == 0)
    {
        printf("exit\n");
        exit(0);
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
