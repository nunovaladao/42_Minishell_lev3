/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aspas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:24:58 by nmoreira          #+#    #+#             */
/*   Updated: 2023/05/18 18:24:58 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ex_status;

int	countaspas(char *str)
{
	char	c;
	int		i;
	int		pairs;

	i = 0;
	pairs = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i];
			i++;
			pairs++;
			while (str[i] != c)
				i++;
		}
		i++;
	}
	return (pairs);
}

void	wordoutaspas(t_token *node)
{
	char	c;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ((ft_strlen(node->word) \
	- (countaspas(node->word) * 2) + 1)));
	while (node->word[i] != '\0')
	{
		if (node->word[i] == '\'' || node->word[i] == '\"')
		{
			c = node->word[i];
			i++;
			while (node->word[i] != c)
				str[j++] = node->word[i++];
			i++;
		}
		else
			str[j++] = node->word[i++];
	}
	free(node->word);
	str[j] = '\0';
	node->word = str;
}

int	rmvaspas(t_shell *sh)
{
	t_token	*node;

	node = NULL;
	node = sh->head_token;
	while (node)
	{
		if (!ft_strchr(node->word, '$'))
			wordoutaspas(node);
		node = node->next;
	}
	return (0);
}