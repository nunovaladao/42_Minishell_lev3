/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:23:24 by nmoreira          #+#    #+#             */
/*   Updated: 2023/02/12 11:23:24 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void node_type(t_shell *sh, char c)
{
	t_token *last;

	last = sh->head_token;
	while (last->next)
		last = last->next;
	last->type = c;

}

/*função de teste - imprime a lista - palavras e tipo*/
void	print_list(t_shell *sh)
{
	t_token	*last;

	last = sh->head_token;
	while (last)
	{
		ft_putstr_fd(last->word, 1);
		ft_putstr_fd(&last->type, 1);
		last = last->next;
	}
	ft_putstr_fd("\n", 1);
}

void	*node(t_shell *sh, char *word)
{
	t_token	*new;
	t_token *last;

	new = NULL;
	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->word = word;
	new->type = 'N';
	new->next = NULL;
	new->prev = NULL;
	if (sh->head_token == NULL)
	{
		sh->head_token = new;
		sh->head_token->next = new->next;
	}	
	last = sh->head_token;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (NULL);
}

/*funções utilizadas no push swap para a double list*/

// void	insert_node_after(t_shell *sh, t_token *node)
// {
// 	t_token *last;

// 	if (!sh->head_token || !node)
// 		return ;
// 	last = sh->head_token;
// 	while (last->next != NULL)
// 		last = last->next;
// 	last->next = node;
// 	node->prev = last;
// }

// void	insert_node_before(t_node *list, t_node *node)
// {
// 	if (!list || !node)
// 		return ;
// 	node->prev = list->prev;
// 	node->next = list;
// 	if (node->prev)
// 		node->prev->next = node;
// 	if (node->next)
// 		node->next->prev = node;
// }

// void	free_node(t_node *node)
// {
// 	if (node->next)
// 		node->next->prev = node->prev;
// 	if (node->prev)
// 		node->prev->next = node->next;
// 	free(node);
// }

// void	free_list(t_node *list)
// {
// 	t_node	*current;

// 	current = list;
// 	if (!list)
// 		return ;
// 	while (list != NULL)
// 	{
// 		current = list->next;
// 		free(list);
// 		list = current;
// 	}
// 	list = NULL;
// }
