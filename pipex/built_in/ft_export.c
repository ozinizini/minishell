/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:29:55 by ozini             #+#    #+#             */
/*   Updated: 2024/05/08 18:10:26 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static	void	print_export_list(t_list *export)
{
	char	*variable;
	int		i;
	int		equal_sign;

	while (export != NULL)
	{
		printf("declare -x ");
		variable = (char *)export->content;
		i = 0;
		equal_sign = 0;
		while (variable[i])
		{
			printf("%c", variable[i]);
			if (variable[i++] == '=')
			{
				equal_sign = 1;
				printf("\"");
			}
		}
		if (equal_sign)
			printf("\"\n");
		else
			printf("\n");
		export = export->next;
	}
}

static int	export_to_list(t_list **list, char *export_variable)
{
	int		env_variable_position;

	env_variable_position = env_variable_exists(*list, export_variable);
	if (!env_variable_position)
		return (add_new_env_variable(list, export_variable));
	else if (env_variable_position != -1)
		return (replace_existing_env_variable(list, export_variable,
				env_variable_position));
	else
		return (1);
}

int	ft_export(t_list **env, t_list **export_list, char *export_variable)
{
	t_list	*temp;
	int		i;

	temp = NULL;
	i = 1;
	if (export_variable[0] == '=')
		return (minishell_error_message_return("not a valid identifier",
				export_variable, 1));
	if (forbidden_variable_name(export_variable))
		return (1);
	if (string_contains_equal_sign(export_variable))
	{
		if (export_to_list(export_list, export_variable))
			return (1);
		else
			return (export_to_list(env, export_variable));
	}
	else
		return (export_to_list(export_list, export_variable));
}

int	handle_variables_export(t_list **env,
	t_list **export_list, char **export_variables,
	int number_of_variables)
{
	int	i;
	int	return_value;
	int	ft_export_value;

	i = 1;
	return_value = 0;
	ft_export_value = 0;
	if (!number_of_variables)
	{
		sort_list(*export_list);
		print_export_list(*export_list);
	}
	while (export_variables[i] != NULL)
	{
		ft_export_value = ft_export(env, export_list, export_variables[i++]);
		if (ft_export_value > 0)
			return_value = 1;
		else if (ft_export_value == -1)
		{
			return_value = 1;
			break ;
		}
	}
	return (return_value);
}
