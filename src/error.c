/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:03:22 by nmoreira          #+#    #+#             */
/*   Updated: 2023/05/16 16:03:22 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int error_quotes(char erro)
{
	if (erro == '\'')
		write(1, "minishell: unexpected error while looking for matching quotes \'\n", 65);	
	if (erro == '\"')
		write(1, "minishell: unexpected error while looking for matching quotes \"\n", 65);
	return (0);
}
