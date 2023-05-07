/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:12:18 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/07 22:40:27 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_shell
{
	char *str;
    char *line;
}				t_shell;

void init(int ac, char **av);
char show_prompt(t_shell *cmd);
void signals();


#endif
