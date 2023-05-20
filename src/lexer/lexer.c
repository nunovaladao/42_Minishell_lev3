/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:10:06 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/19 19:28:50 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int check_input(t_shell *shell)
{
    if (div_input(shell))
        return (1);
    if (operators(shell))
        return (1);
    return (0);
}