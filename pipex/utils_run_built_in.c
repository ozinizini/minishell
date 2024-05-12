/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_run_built_in.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:38:21 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 16:48:10 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_run_built_in.h"

int	is_built_in( char *command)
{
	if (!ft_strcmp(command, "pwd"))
		return (1);
	else if (!ft_strcmp(command, "cd"))
		return (1);
	else if (!ft_strcmp(command, "env"))
		return (1);
	else if (!ft_strcmp(command, "export"))
		return (1);
	else if (!ft_strcmp(command, "unset"))
		return (1);
	else if (!ft_strcmp(command, "exit"))
		return (1);
	else if (!ft_strcmp(command, "echo"))
		return (1);
	else
		return (0);
}

int	run_built_in(char **command, t_test **test)
{
	int	exit_status;

	exit_status = 0;
	if (ft_strcmp(command[0], "pwd") == 0)
		exit_status = ft_pwd();
	else if (ft_strcmp(command[0], "cd") == 0)
		exit_status = ft_cd(command[1], &(*test)->env, &(*test)->export_list);
	else if (ft_strcmp(command[0], "env") == 0)
		exit_status = ft_env((*test)->env);
	else if (strcmp(command[0], "export") == 0)
		exit_status = handle_variables_export(&(*test)->env,
				&(*test)->export_list, command,
				count_strings(command) - 1);
	else if (strcmp(command[0], "unset") == 0)
		exit_status = handle_variables_unset(&(*test)->env,
				&(*test)->export_list, command,
				count_strings(command) - 1);
	else if (strcmp(command[0], "exit") == 0)
		ft_exit(command[1], &exit_status,
			count_strings(command) - 1, (*test)->number_of_processes);
	else if (strcmp(command[0], "echo") == 0)
		exit_status = ft_echo(command, count_strings(command) - 1);
	return (exit_status);
}
