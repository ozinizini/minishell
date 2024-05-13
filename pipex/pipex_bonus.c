/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:12:03 by ozini             #+#    #+#             */
/*   Updated: 2024/05/13 12:38:33 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_error_messages.h"
#include "utils_memory_management.h"
#include "utils_paths.h"
#include "utils_processes.h"
#include "utils_processes_bonus.h"
#include "pipex_bonus.h"
#include "utils_heredoc_bonus.h"
#include "utils_structs.h"
#include "utils_run_built_in.h"
#include "./parser/minishell.h"

static int	return_exit_status(t_test *test, pid_t *pidc_array)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	status = 0;
	exit_status = 0;
	while (i < test->number_of_processes)
	{
		waitpid(pidc_array[i], &status, 0);
		i++;
	}
	free(pidc_array);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}

static void	handle_parent(t_test *test, int children_counter)
{
	children_counter++;
	if (children_counter == 1 && test->number_of_processes > 1)
		close(test->fd_pipe[0][1]);
	else if (children_counter > 1 && children_counter
		< test->number_of_processes)
	{
		close(test->fd_pipe[children_counter - 2][0]);
		close(test->fd_pipe[children_counter - 1][1]);
	}
	else if (children_counter == test->number_of_processes
		&& test->number_of_processes > 1)
		close(test->fd_pipe[children_counter - 2][0]);
	if (children_counter < test->number_of_processes - 1)
	{
		if (pipe(test->fd_pipe[children_counter]) == -1)
			error_message("Error: pipe failed");
	}
}

static void	handle_children(t_list *processes,
	t_test *test, int children_counter)
{
	if (children_counter == 0)
		infile_child_process_bonus(processes, test, test->fd_pipe);
	else if (children_counter < test->number_of_processes - 1)
		intermediate_children_process(processes, test,
			test->fd_pipe[children_counter - 1],
			test->fd_pipe[children_counter]);
	else
		outfile_child_process_bonus(processes, test,
			test->fd_pipe[children_counter - 1]);
}

static int	handle_processes_bonus(t_list *processes, t_test *test)
{
	int		children_counter;
	pid_t	pidc;
	pid_t	*pidc_array;

	pidc = 1;
	children_counter = 0;
	pidc_array = malloc(sizeof(pid_t) * test->number_of_processes);
	if (pidc_array == NULL)
		error_message("Error: Memory allocation failed");
	while (children_counter < test->number_of_processes)
	{
		pidc = fork();
		if (pidc == -1)
			error_message(strerror(errno));
		else if (pidc == 0)
			handle_children(processes, test, children_counter);
		else
		{
			pidc_array[children_counter] = pidc;
			handle_parent(test, children_counter++);
		}
		processes = processes->next;
	}
	return (return_exit_status(test, pidc_array));
}

int	pipex(t_list *processes, t_list **env, t_list **export_list)
{
	t_test	*test;
	int		exit_status;

	exit_status = 0;
	test = init_test(processes, &(*env), &(*export_list));
	if (test->number_of_processes == 0)
		return (exit_status);
	init_heredocs(processes);
	if (test->number_of_processes == 1
		&& is_built_in(((t_process *)processes->content)->command[0]))
		exit_status = lonesome_built_in(processes, &test);
	else
		exit_status = handle_processes_bonus(processes, test);
	free_t_test(test);
	return (exit_status);
}
