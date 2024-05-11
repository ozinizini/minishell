/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_variables_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:54:40 by ozini             #+#    #+#             */
/*   Updated: 2024/05/08 18:09:58 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	excluding_plus_sign(char *export_variable,
	char *var_value, t_list **node)
{
	char	*var_name;
	char	*new_export_variable;

	new_export_variable = NULL;
	var_name = NULL;
	var_name = variable_name(export_variable);
	if (var_name == NULL)
		return (error_message_return("Memory allocation failed\n", 1));
	new_export_variable = ft_strjoin(var_name, var_value);
	if (new_export_variable == NULL)
		return (free(var_name),
			error_message_return("Memory allocation failed\n", 1));
	*node = ft_lstnew_string(new_export_variable);
	return (free(var_name), free(new_export_variable), 0);
}

int	add_new_env_variable(t_list **env, char *export_variable)
{
	t_list	*node;
	char	*var_value;

	node = NULL;
	var_value = strnstr(export_variable, "+", ft_strlen(export_variable));
	if (var_value++)
	{
		if (excluding_plus_sign(export_variable, var_value, &node))
			return (1);
	}
	else
		node = ft_lstnew_string((void *)export_variable);
	ft_lstadd_back(&(*env), node);
	return (0);
}

static	int	join_variable_content(t_list *temp, char *export_variable)
{
	char	*new_added_content;
	char	*new_variable_content;

	new_added_content = ft_strnstr(export_variable,
			"=", ft_strlen(export_variable));
	new_added_content++;
	new_variable_content = ft_strjoin((const char *)
			temp->content, new_added_content);
	if (new_variable_content == NULL)
	{
		printf("Memory allocation fails here\n");
		return (error_message_return("Memory allocation failed\n", 2));
	}
	free(temp->content);
	temp->content = NULL;
	temp->content = new_variable_content;
	return (0);
}

static	int	replace_variable_content(t_list *temp, char *export_variable)
{
	if (temp->content)
	{
		free(temp->content);
		temp->content = NULL;
	}
	temp->content = (void *)ft_strdup(export_variable);
	if (!temp->content)
	{
		ft_putstr_fd("export command: Memory allocation failed\n", 2);
		return (1);
	}
	return (0);
}

int	replace_existing_env_variable(t_list **env, char *export_variable,
	int env_variable_position)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = *env;
	while (i++ < env_variable_position)
		temp = temp->next;
	if (strnstr(export_variable, "+", ft_strlen(export_variable)))
		return (join_variable_content(temp, export_variable));
	else if (strnstr(export_variable, "=", ft_strlen(export_variable)))
		return (replace_variable_content(temp, export_variable));
	else
		return (0);
}
