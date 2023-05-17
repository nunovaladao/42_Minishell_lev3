/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:12:18 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/17 15:30:38 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int g_ex_status;

typedef struct s_token
{
	char			*word;
	char			type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_cmds
{
	char **cmd_line;
	char *new_dir;
	char	*var;
	char	*value;
	struct s_cmds *next;
}				t_cmds;

typedef struct s_shell
{
	t_cmds *cmds;
	t_token *head_token;
    char *cmd_line;
	int		i; // posição na string
	int		wd_lim; // posição na string
	int		dquotes; // double quotes
	int		squotes; // single quotes
	char		**envp;
	pid_t		pid;
}	t_shell;

// main
void init(int ac, char **av, char **envp, t_shell *shell);
char *show_prompt();
void signals();

// Builtins
int builtins(t_cmds *cmds, t_shell *shell);
int built_echo(t_cmds *cmds);
int built_pwd();
int built_cd(t_cmds *cmds);
int built_exit(t_cmds *cmds);
int built_env(t_shell *shell);
int built_export(t_shell *shell ,t_cmds *cmds);
int built_unset(t_cmds *cmds, t_shell *shell);
void clear_screen();

// Env
int put_var_env(t_cmds *cmds, t_shell *shell);
int pos_envp(char *var, char **envp);
void remv_var_env(char *var, t_shell *shell);

// Utils
int nb_of_args(t_cmds *cmds);
int	pos_char(char *str, char c);
int args_numbers(char *str);

// Utils Env
char **mtr_dup(char **matriz);
int mtr_len(char **matriz);
void mtr_free(char **matriz);
char **mtr_addnew(char *str, char **matrizold);
char **mtr_rmv(int pos, char **matrizold);

// Utils list
void node_type(t_shell *sh, char c);
void	print_list(t_shell *sh);
void	*node(t_shell *sh, char *word);

// Errors
int error_quotes(char erro);

#endif
