/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:34:51 by ozini             #+#    #+#             */
/*   Updated: 2024/05/10 11:57:11 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	ft_unset(t_list **env, t_list **export_list, char *export_variable)
{
	int	list_pos;

	list_pos = 0;
	if (strnstr(export_variable, "=", ft_strlen(export_variable)))
		return (minishell_error_message_return("not a valid identifier",
				export_variable, 1));
	if (forbidden_variable_name(export_variable))
		return (1);
	list_pos = env_variable_exists(*env, export_variable);
	if (list_pos > 0)
		ft_delete_node(&(*env), list_pos);
	else if (list_pos == -1)
		return (-1);
	list_pos = env_variable_exists(*export_list, export_variable);
	if (list_pos)
		ft_delete_node(&(*export_list), list_pos);
	else if (list_pos == -1)
		return (-1);
	return (0);
}

int	handle_variables_unset(t_list **env,
	t_list **export_list, char **export_variables,
	int number_of_variables)
{
	int	i;
	int	return_value;
	int	ft_unset_value;

	i = 1;
	return_value = 0;
	ft_unset_value = 0;
	if (!number_of_variables)
		return (return_value);
	while (export_variables[i] != NULL)
	{
		ft_unset_value = ft_unset(env, export_list, export_variables[i++]);
		if (ft_unset_value > 0)
			return_value = 1;
		else if (ft_unset_value == -1)
		{
			return_value = 1;
			break ;
		}
	}
	return (return_value);
}
