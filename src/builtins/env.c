/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:01:09 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/15 11:12:08 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int built_env(t_shell *shell)
{
    int i;

    i = 0;
    if (!*shell->envp)
        return (0);
    while (shell->envp[i] && ft_strchr(shell->envp[i], '='))
        printf("%s\n", shell->envp[i++]);
    return (0);
}