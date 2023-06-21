/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:29:58 by nsoares-          #+#    #+#             */
/*   Updated: 2023/06/19 16:23:49 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// se existir / na str /bin/ls, o ft_strchr retorna a string desde o primeiro /
char *search_path(t_shell *shell, t_cmds *cmds)
{
    char **paths;
    char *cmd;

    if (ft_strchr(cmds->cmd_line[0], '/') && access(cmds->cmd_line[0], F_OK) == 0)
        return (ft_strdup(cmds->cmd_line[0]));
    paths = get_paths(shell);
    cmd = find_executable(paths, cmds->cmd_line[0]);
    mtr_free(paths);
    return (cmd);
}

char **get_paths(t_shell *shell)
{
    char **paths;
    char *path_env;
    
	path_env = NULL;
    path_env = get_env("PATH", shell);
    if (!path_env)
        return (NULL);
    paths = ft_split(path_env, ':');
    free(path_env);
	path_env = NULL; // alteração dava invalid frre pointer - get_env não devolve pointer
    return (paths);
}

char *find_executable(char **paths, const char *command)
{
    char *temp;
    char *cmd;
    
    cmd = NULL;
    while (*paths)
    {
        temp = ft_strjoin(*paths, "/");
        cmd = ft_strjoin(temp, command);
        free(temp);
        if (access(cmd, F_OK) == 0)
            return (cmd);
        free(cmd);
        paths++;
    }
    return (NULL);
}
