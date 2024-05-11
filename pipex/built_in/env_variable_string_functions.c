/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable_string_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:01:58 by ozini             #+#    #+#             */
/*   Updated: 2024/05/08 18:09:52 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	forbidden_characters(char *export_variable,
	char character, int plus_sign_flag)
{
	if (!plus_sign_flag)
	{
		if (!ft_isalnum(character) && character != '_')
			return (minishell_error_message_return("not a valid identifier",
					export_variable, 1));
		else
			return (0);
	}
	else
	{
		if (string_contains_equal_sign(export_variable)
			&& !ft_isalnum(character)
			&& character != '_' && character != '+')
			return (minishell_error_message_return("not a valid identifier",
					export_variable, 1));
		else if (!string_contains_equal_sign(export_variable)
			&& !ft_isalnum(character) && character != '_')
			return (minishell_error_message_return("not a valid identifier",
					export_variable, 1));
		else
			return (0);
	}
}

int	forbidden_variable_name(char *exp_var)
{
	size_t	i;
	char	*str;
	size_t	var_name_length;

	i = 0;
	var_name_length = ft_strlen(exp_var);
	str = strnstr(exp_var, "=", ft_strlen(exp_var));
	if (str)
		var_name_length = ft_strlen(exp_var) - ft_strlen(str);
	while (exp_var[i] != '\0' && exp_var[i] != '=')
	{
		if (i == 0 && (exp_var[i] == ' ' || exp_var[i]
				== '+' || exp_var[i] == '=' || ft_isdigit(exp_var[i])))
			return (minishell_error_message_return("not a valid identifier",
					exp_var, 1));
		if (i < var_name_length - 1)
		{
			if (forbidden_characters(exp_var, exp_var[i], 0))
				return (1);
		}
		else if (forbidden_characters(exp_var, exp_var[i], 1))
			return (1);
		i++;
	}
	return (0);
}

int	string_contains_equal_sign(char *export_variable)
{
	size_t	equal_char_position;

	equal_char_position = 0;
	while ((export_variable[equal_char_position] != '=') && (export_variable
			[equal_char_position] != '\0'))
		equal_char_position++;
	return (equal_char_position != ft_strlen(export_variable));
}

char	*variable_name(char *export_variable)
{
	size_t	equal_char_position;
	char	*substr;

	equal_char_position = 0;
	while ((export_variable[equal_char_position] != '=') && (export_variable
			[equal_char_position] != '\0'))
		equal_char_position++;
	if (ft_strnstr(export_variable, "+", ft_strlen(export_variable)))
		equal_char_position--;
	substr = ft_substr((const char *)export_variable, 0, equal_char_position);
	if (substr == NULL)
		return (NULL);
	return (substr);
}
