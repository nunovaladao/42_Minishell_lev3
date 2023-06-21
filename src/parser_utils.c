/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 03:45:41 by nmoreira          #+#    #+#             */
/*   Updated: 2023/06/10 03:45:41 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cmds(t_shell *sh)
{
    t_cmds *current = sh->cmds;
	int i = 0;

	if(!sh->cmds)
		return ;
	while (current)
	{
		i = 0;
    	while (current->cmd_line[i]) 
		{
        	i++;
    	}
		current = current->next;
	}
}

void fill_index(t_shell *sh)
{
	int  i = 0;
	t_cmds *head;

	if(!sh->cmds)
		return ;
	head = sh->cmds;
	while (head)
	{
		head->index = i;
		i++;
		head = head->next;
	}
	sh->cmds->total = i + 1; // porque estamos a considerar o zero no i
}

void	*node_cmds(t_cmds **node)
{
	t_cmds	*new;
	t_cmds *last;

	new = NULL;
	new = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	if (*node == NULL)
		*node = new;
	else
	{
		last = *node;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	return (NULL);
}

void free_listcmd(t_cmds *head)
{
	char **cmd_line;
	int i;
	t_cmds *next;

    while (head != NULL)
    {
        // Liberta o array cmd_line
        if (head->cmd_line != NULL)
        {
            cmd_line = head->cmd_line;
            i = 0;
            while (cmd_line[i] != NULL)
            {
                free(cmd_line[i]);
                i++;
            }
            free(cmd_line);
        }
        free(head->new_dir);
        free(head->path);
        free(head->var);
        free(head->value);
		head->index = 0;
		next = head->next;
        free(head);
        head = next;
    }
}
