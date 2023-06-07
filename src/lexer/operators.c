/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:40:41 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/30 16:11:32 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_operator(char c)
{
	if (c == 60) 		// <
		return (1);
	if (c == 62)		// >
		return (1);
	if (c == 124) 		// |
		return (1);
	return (0);
}

/*Podem existir mais condições de erro*/
int operators(t_shell *shell)
{
    t_token	*start;

	start = NULL;
	start = shell->head_token;
	while (start)
	{
		if (start->type == 'O')
		{
			if (start->prev == NULL || start->next->type == 'O')
			{
				g_ex_status = 2;
				printf("minishell: syntax error near unexpected token '%s'\n",
					start->word);
				return (1);
			}
		}
		start = start->next;
	}
	return (0);
}