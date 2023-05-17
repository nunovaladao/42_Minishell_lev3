/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:07:59 by nmoreira          #+#    #+#             */
/*   Updated: 2023/05/14 20:07:59 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*dest;
// 	size_t	j;

// 	dest = (char *)malloc(len + 1);
// 	if (!s || !dest)
// 		return (0);
// 	j = 0;
// 	while (start < ft_strlen(s) && j < len)
// 		dest[j++] = s[start++];
// 	dest[j] = '\0';
// 	return (dest);
// }

int check_quotes(t_shell *sh)
{
	if (sh->cmd_line[sh->i] == 34)
	{
		sh->i++;
		while (sh->cmd_line[sh->i] != 34)
		{
			if (sh->cmd_line[sh->i] == '\0')
				return (error_quotes('\"'));
			sh->i++;
		}
	}
	if (sh->cmd_line[sh->i] == 39)
	{
		sh->i++;
		while (sh->cmd_line[sh->i] != 39)
		{
			if (sh->cmd_line[sh->i] == '\0')
				return (error_quotes('\''));
			sh->i++;
		}
	}
	return (0);
}

int is_operator(char c)
{
	{
	if (c == 60) 		// <
		return (1);
	if (c == 62)		// >
		return (1);
	if (c == 124) 		// |
		return (1);
	return (0);
}
}

void lexer_op(t_shell *sh)
{
	if (sh->i - sh->wd_lim)
		node(sh, ft_substr(sh->cmd_line, sh->wd_lim, (sh->i - sh->wd_lim))); // se tivermos o operador junto das palavras sem espaços
	sh->wd_lim = sh->i;
	if (sh->cmd_line[sh->i] == 60 || sh->cmd_line[sh->i] == 62)
	{
		if (sh->cmd_line[sh->i + 1] && sh->cmd_line[sh->i] == sh->cmd_line[sh->i + 1])
			sh->i += 2;
		else
			sh->i++;
	}
	else
		sh->i++;
	if (sh->i - sh->wd_lim)
		node(sh, ft_substr(sh->cmd_line, sh->wd_lim, (sh->i - sh->wd_lim)));
	node_type(sh, 'O');
}

void lexer_word(t_shell *sh)
{
	if (sh->i - sh->wd_lim)
		node(sh, ft_substr(sh->cmd_line, sh->wd_lim, (sh->i - sh->wd_lim)));
	while (sh->cmd_line[sh->i] == ' ')
		sh->i++;
	sh->wd_lim = sh->i;
}

int div_input(t_shell *sh)
{
	sh->i = 0;
	sh->wd_lim = 0;
	while (sh->cmd_line[sh->i] == '\0')
	{
		if (sh->cmd_line[sh->i] == '\'' || sh->cmd_line[sh->i] == '\"')
		{
			if (check_quotes(sh))
				return (1);
		}
		else if (is_operator(sh->cmd_line[sh->i]))
			lexer_op(sh);
		else if (sh->cmd_line[sh->i] == ' ')
			lexer_word(sh);
		else
			sh->i++;
	}
	return (0);
}