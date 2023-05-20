/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:55:12 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/19 19:31:49 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int nb_of_args(t_cmds *cmds)
{
    int i;

    i = 0;
    while (cmds->cmd_line[i] != NULL)
        i++;
    return (i);
}

int	pos_char(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	if (c == '\0')
		return (i);
	return (-1);
}

int error_quotes(char error)
{
	if (error == '\'')
		write(1, "minishell: unexpected error while looking for matching quotes \'\n", 65);	
	if (error == '\"')
		write(1, "minishell: unexpected error while looking for matching quotes \"\n", 65);
	return (0);
}