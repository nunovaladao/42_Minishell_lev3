/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:58:02 by nmoreira          #+#    #+#             */
/*   Updated: 2023/07/01 12:58:02 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_ex_status;

static char	*concateher(char *new_str, char *rest)
{
	char	*tmp;

	tmp = NULL;
	if (new_str && rest)
	{
		tmp = ft_strdup(new_str);
		free(new_str);
		new_str = ft_strjoin(tmp, rest);
		free(tmp);
	}
	else if (new_str)
		return (new_str);
	else if (rest)
		new_str = ft_strdup(rest);
	return (new_str);
}

static char	*dorest(int *i, char *str)
{
	int		start;
	char	*rest;

	start = *i;
	rest = NULL;
	while (str[(*i)] != '$' && str[(*i)] != '\0')
			(*i)++;
	if ((*i) > start)
	{
		rest = ft_substr(str, start, (*i) - start);
		return (rest);
	}
	return (NULL);
}

static char	*concatenate_strings(char *str1, char *str2)
{
	char	*result;

	result = NULL;
	if (str1 && str2)
	{
		result = ft_strjoin(str1, str2);
		free(str1);
		free(str2);
		return (result);
	}
	else if (str1)
		return (ft_strdup(str1));
	else if (str2)
		return (ft_strdup(str2));
	else
		return (NULL);
}

char	*getenvher(t_shell *sh, char *str)
{
	int		i;
	char	*env;
	char	*rest;
	char	*result;
	char	*new_str;

	i = 0;
	rest = NULL;
	env = NULL;
	result = NULL;
	new_str = NULL;
	while (str[i])
	{
		rest = dorest(&i, str);
		env = dorexpher(&i, str, sh);
		result = concatenate_strings(rest, env);
		new_str = concateher(new_str, result);
		if (result)
			free(result);
	}
	return (new_str);
}

char	*her_env(t_shell *sh, char *str)
{
	char	*tmp;
	char	*tmp1;

	tmp = NULL;
	tmp1 = NULL;
	if (!str)
		return (NULL);
	if (ft_strchr(str, '$'))
	{
		tmp = ft_strdup(str);
		tmp1 = getenvher(sh, tmp);
		free(tmp);
	}
	return (tmp1);
}
