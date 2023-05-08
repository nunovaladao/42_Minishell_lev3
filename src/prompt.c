/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:57:00 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/08 13:48:32 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *show_prompt()
{
    char *line;
    char *str;
    
    line = readline("minishell$ ");
    if (line == NULL)
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
