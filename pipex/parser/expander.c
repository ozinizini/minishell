/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:46:22 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/09 19:21:13 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_char(char *line, char *expanded_line, size_t *i)
{
	expanded_line[i[1]] = line[i[0]];
	i[0]++;
	i[1]++;
}

void	manage_quotes(char *line, char *expanded_line, size_t *i)
{
	copy_char(line, expanded_line, i);
	while (line[i[0]] && line[i[0]] != '\'')
		copy_char(line, expanded_line, i);
	copy_char(line, expanded_line, i);
}

void	manage_variable(char *line, char *expanded_line, t_list *env, size_t *i)
{
	char	*variable_name;
	char	*variable_value;
	int		j;

	j = 0;
	variable_name = NULL;
	variable_value = NULL;
	variable_name = get_variable_name(line + i[0]);
	variable_value = get_variable_value(variable_name, env);
	if (variable_value)
	{
		while (variable_value[j])
		{
			expanded_line[i[1]] = variable_value[j];
			j++;
			i[1]++;
		}
	}
	i[0]++;
	i[0] += ft_strlen(variable_name);
	if (variable_name)
		free(variable_name);
}

char	*expand_line(char *line, size_t len, t_list *env)
{
	char	*expanded_line;
	size_t	i[2];

	expanded_line = NULL;
	i[0] = 0;
	i[1] = 0;
	expanded_line = malloc((len + 1) * sizeof(char));
	if (!expanded_line)
		return (NULL);
	while (line[i[0]])
	{
		if (line[i[0]] == '\'')
			manage_quotes(line, expanded_line, i);
		else if (line[i[0]] == '$'
			&& (ft_isalnum(line[i[0] + 1]) || line[i[0] + 1] == '_'))
			manage_variable(line, expanded_line, env, i);
		else
			copy_char(line, expanded_line, i);
	}
	expanded_line[i[1]] = '\0';
	return (expanded_line);
}

char	*expander(char *line, t_list *env)
{
	char	*expanded_line;
	size_t	len;

	expanded_line = NULL;
	len = get_expanded_len(line, env);
	expanded_line = expand_line(line, len, env);
	free (line);
	return (expanded_line);
}
