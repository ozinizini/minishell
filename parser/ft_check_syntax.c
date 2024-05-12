/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:18:19 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/12 14:03:01 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *line)
{
	size_t	i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c == '\'' || c == '\"')
		{
			i++;
			while (line[i] && line[i] != c)
				i++;
			if (!line[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_pipes(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '|')
		return (2);
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			i = skip_all_quotes(line, i);
		if (line[i] == '|')
		{
			i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '|' || !line[i])
				return (2);
			continue ;
		}
		i++;
	}
	return (0);
}

int	check_redir(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '<' || line[i] == '>')
		{
			while (line[i] == '<' || line[i] == '>')
				i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '|' || line[i] == '<'
				|| line[i] == '>' || !line[i])
				return (3);
		}
		while (line[i] != '<' && line[i] != '>' && line[i])
			i++;
	}
	return (0);
}

int	ft_check_syntax(char *line)
{
	int		check;

	check = 0;
	check = check_quotes(line);
	if (check == 0)
		check = check_pipes(line);
	if (check == 0)
		check = check_redir(line);
	return (check);
}
