/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:18:19 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/18 18:10:49 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(char *line)
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

static int	check_pipes(char *line)
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

static int	check_char(char *line, size_t i)
{
	if (line[i] == line[i + 1])
		i++;
	if (line[i + 1] == '<' || line[i + 1] == '>')
		return (0);
	return (1);
}

int	check_redir(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '<' || line[i] == '>')
		{
			if (!check_char(line, i))
				return (3);
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
	if (check_quotes(line))
	{
		write(2, "minishell: syntax error: unclosed quotes\n", 42);
		return (258);
	}
	if (check_pipes(line))
	{
		write(2, "minishell: syntax error: empty pipe\n", 37);
		return (258);
	}
	if (check_redir(line))
	{
		write(2, "minishell: syntax error: invalid redirection\n", 46);
		return (258);
	}
	return (check);
}
