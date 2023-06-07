/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:20:03 by nsoares-          #+#    #+#             */
/*   Updated: 2023/06/05 22:11:06 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void redirect_output(char *filename) 
{
    int fd;
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

void redirect_append(char *filename)
{
    int fd;
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

void redirect_input(char *filename)
{
    int fd;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo de entrada");
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
}

int check_redir(t_cmds *cmds)
{
    for (int i = 0; cmds->cmd_line[i] != NULL; i++)
    {
        if (ft_strcmp(cmds->cmd_line[i], ">") == 0)
        {
            redirect_output(cmds->cmd_line[i + 1]);
            // Remover os argumentos de redirecionamento do comando
            cmds->cmd_line[i] = NULL;
            cmds->cmd_line[i + 1] = NULL;
            return 1;
        }
        else if (ft_strcmp(cmds->cmd_line[i], ">>") == 0)
        {
            redirect_append(cmds->cmd_line[i + 1]);
            // Remover os argumentos de redirecionamento do comando
            cmds->cmd_line[i] = NULL;
            cmds->cmd_line[i + 1] = NULL;
            return 1;
        }
        else if (ft_strcmp(cmds->cmd_line[i], "<") == 0)
        {
            redirect_input(cmds->cmd_line[i + 1]);
            // Remover os argumentos de redirecionamento do comando
            cmds->cmd_line[i] = NULL;
            cmds->cmd_line[i + 1] = NULL;
            return 1;
        }
    }
    return 0;
}
