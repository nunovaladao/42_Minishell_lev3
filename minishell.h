/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:12:18 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/10 20:59:09 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmds
{
	char **cmd_line;
	char *new_dir;
}				t_cmds;

typedef struct s_shell
{
	t_cmds *cmds;
    char *cmd_line;
}				t_shell;

// main
void init(int ac, char **av);
char *show_prompt();
void signals();

// Builtins
int builtins(t_cmds *cmds);
int built_echo(t_cmds *cmds);
int built_pwd();
int built_cd(t_cmds *cmds);
void built_exit(t_cmds *cmds);
void clear_screen();

// Utils
int nb_of_args(t_cmds *cmds);

#endif
