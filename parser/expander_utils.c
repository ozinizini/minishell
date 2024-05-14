/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:56:44 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/13 18:44:26 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	skip_variable(char *line, size_t i)
{
	i++;
	while (ft_isalnum(line[i]) || line[i] == '_' || line[i] == '?')
	{
		i++;
	}
	return (i);
}

int	compare_name(char *variable_name, char *env)
{
	size_t	i;

	i = 0;
	while (env[i] != '=' && variable_name[i])
	{
		if (variable_name[i] != env[i])
			return (0);
		i++;
	}
	if (variable_name[i] || env[i] != '=')
		return (0);
	return (1);
}

char	*get_variable_name(char *str)
{
	char	*variable_name;
	size_t	i;

	i = 1;
	variable_name = NULL;
	while (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '?')
		i++;
	i--;
	variable_name = ft_substr(str, 1, i);
	return (variable_name);
}

char	*get_variable_value(char *variable_name, t_list *env)
{
	char	*variable_value;

	variable_value = NULL;
	while (env)
	{
		if (compare_name(variable_name, env->content))
			variable_value = env->content + ft_strlen(variable_name) + 1;
		env = env->next;
	}
	return (variable_value);
}
