/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:49:58 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 14:45:11 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_processes.h"
#include "utils_error_messages.h"
#include "utils_memory_management.h"
#include "utils_paths.h"
#include "./parser/minishell.h"
#include "../built_in/built_in.h"
#include "utils_run_built_in.h"

static void	execute_command(t_list *list, char **env, char *command_path)
{
	if (access(command_path, F_OK) != -1)
	{
		if (access(command_path, R_OK) != -1)
			execve(command_path, ((t_process *)list->content)->command, env);
	}
	else
	{
		bash_error_message("command not found", command_path);
		exit(127);
	}
}

void	exec_first_child(t_list *list, t_test *test, int **fd_pipe)
{
	char	*command_path;
	char	**env_array;

	command_path = NULL;
	env_array = NULL;
	if (fd_pipe)
		close(fd_pipe[0][1]);
	if (is_built_in(((t_process *)list->content)->command[0]))
		exit(run_built_in(((t_process *)list->content)->command, &test));
	env_array = string_list_to_bidimensional_array(test->env);
	if (env_array == NULL)
		error_message("Error: Memory allocation failed\n");
	command_path = check_path(((t_process *)list->content)
			->command[0], env_array);
	if (command_path == NULL)
	{
		free_2d_char_array(env_array);
		error_message("Error: Memory allocation failed\n");
	}
	execute_command(list, env_array, command_path);
	perror("bash");
	free(command_path);
	free_2d_char_array(env_array);
}

void	exec_last_child(t_list *list, t_test *test, int *fd_pipe)
{
	char	*command_path;
	char	**env_array;

	command_path = NULL;
	env_array = NULL;
	close(fd_pipe[0]);
	if (is_built_in(((t_process *)list->content)->command[0]))
		exit(run_built_in(((t_process *)list->content)->command, &test));
	env_array = string_list_to_bidimensional_array(test->env);
	if (env_array == NULL)
		error_message("Error: Memory allocation failed\n");
	command_path = check_path(((t_process *)list->content)
			->command[0], env_array);
	if (command_path == NULL)
	{
		free_2d_char_array(env_array);
		error_message("Error: Memory allocation failed\n");
	}
	execute_command(list, env_array, command_path);
	perror("bash");
	free(command_path);
	free_2d_char_array(env_array);
}

void	exec_intermediate_child(t_list *list, t_test *test,
	int *fd_pipe, int *fd_pipe2)
{
	char	*command_path;
	char	**env_array;

	command_path = NULL;
	env_array = NULL;
	close(fd_pipe2[0]);
	close(fd_pipe[0]);
	close(fd_pipe2[1]);
	if (is_built_in(((t_process *)list->content)->command[0]))
		exit(run_built_in(((t_process *)list->content)->command, &test));
	env_array = string_list_to_bidimensional_array(test->env);
	if (env_array == NULL)
		error_message("Error: Memory allocation failed\n");
	command_path = check_path(((t_process *)list->content)
			->command[0], env_array);
	if (command_path == NULL)
	{
		free_2d_char_array(env_array);
		error_message("Error: Memory allocation failed\n");
	}
	execute_command(list, env_array, command_path);
	perror("bash");
	free(command_path);
	free_2d_char_array(env_array);
}
