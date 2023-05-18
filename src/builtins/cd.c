/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:07:46 by nsoares-          #+#    #+#             */
/*   Updated: 2023/05/18 19:41:51 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int get_cd_home(t_shell *shell)
{
    char *go_home;

    go_home = get_env("HOME", shell);
    if (!go_home)
    {
        printf("minishell: cd: HOME not set\n");
        return (g_ex_status = 1); 
    }
    chdir(go_home);
    free(go_home);
    return (g_ex_status = 0);
}

int built_cd(t_cmds *cmds, t_shell *shell)
{
    if (!cmds->cmd_line[1])
        return (get_cd_home(shell));
    if (nb_of_args(cmds) > 2)
    {
        printf("minishell: cd: too many arguments\n");
        return (g_ex_status = 2);
    }
    else
    {
        cmds->oldpwd = getcwd(NULL, 0);
        if (chdir(cmds->cmd_line[1]) == -1)
        {
            ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(cmds->cmd_line[1], STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
            return (g_ex_status = 1);
        }
        cmds->pwd = getcwd(NULL, 0);
        put_var_env("PWD", cmds->pwd, shell);
        put_var_env("OLDPWD", cmds->oldpwd, shell);
        free(cmds->pwd);
        free(cmds->oldpwd);
        g_ex_status = 0;
    }
    return (g_ex_status);
}
