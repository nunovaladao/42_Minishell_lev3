/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:57:50 by nsoares-          #+#    #+#             */
/*   Updated: 2023/07/11 09:35:22 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	valid_n(char *str)
{
	int	i;

	i = 2;
	if (str && ft_strncmp(str, "-n", 2) == 0)
	{
		while (str[i])
		{
			if (str[i] != 'n')
				break ;
			i++;
		}
		return (1);
	}
	return (0);
}

int	built_echo(t_cmds *cmds)
{
	int	i;

	i = 1;
	while (valid_n(cmds->cmd_line[i]) && cmds->cmd_line[i])
		i++;
	while (cmds->cmd_line[i])
	{
		printf("%s", cmds->cmd_line[i++]);
		if (cmds->cmd_line[i])
			printf(" ");
	}
	if (!valid_n(cmds->cmd_line[1]))
		printf("\n");
	return (g_ex_status = 0);
}
