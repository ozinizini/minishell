/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:58:10 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/09 14:23:55 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_variable_size(char *variable, t_list *env)
{
	size_t	i;
	char	*variable_name;
	size_t	variable_size;

	i = 0;
	variable_size = 0;
	variable_name = get_variable_name(variable);
	while (env)
	{
		if (compare_name(variable_name, env->content))
		{
			variable_size = ft_strlen(env->content) - ft_strlen(variable_name);
			variable_size--;
		}
		env = env->next;
	}
	if (variable_name)
		free(variable_name);
	return (variable_size);
}

size_t	get_expanded_len(char *line, t_list *env)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			len += (skip_single_quotes(line, i) - i);
			i = skip_single_quotes(line, i);
		}
		else if (line[i] == '$'
			&& (ft_isalnum(line[i + 1]) || line[i + 1] == '_'))
		{
			len += get_variable_size(line + i, env);
			i = skip_variable(line, i);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}
