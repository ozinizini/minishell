/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:12:03 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 21:39:27 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "./parser/minishell.h"

static int	return_exit_status(t_prompt *prompt, pid_t *pidc_array)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	status = 0;
	exit_status = 0;
	while (i < prompt->number_of_processes)
	{
		waitpid(pidc_array[i], &status, 0);
		i++;
	}
	free(pidc_array);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}

static void	handle_parent(t_prompt *prompt, int children_counter)
{
	children_counter++;
	if (children_counter == 1 && prompt->number_of_processes > 1)
		close(prompt->fd_pipe[0][1]);
	else if (children_counter > 1 && children_counter
		< prompt->number_of_processes)
	{
		close(prompt->fd_pipe[children_counter - 2][0]);
		close(prompt->fd_pipe[children_counter - 1][1]);
	}
	else if (children_counter == prompt->number_of_processes
		&& prompt->number_of_processes > 1)
		close(prompt->fd_pipe[children_counter - 2][0]);
	if (children_counter < prompt->number_of_processes - 1)
	{
		if (pipe(prompt->fd_pipe[children_counter]) == -1)
			error_message("Error: pipe failed");
	}
}

static void	handle_children(t_list *processes,
	t_prompt *prompt, int children_counter)
{
	if (children_counter == 0)
		infile_child_process_bonus(processes, prompt, prompt->fd_pipe);
	else if (children_counter < prompt->number_of_processes - 1)
		intermediate_children_process(processes, prompt,
			prompt->fd_pipe[children_counter - 1],
			prompt->fd_pipe[children_counter]);
	else
		outfile_child_process_bonus(processes, prompt,
			prompt->fd_pipe[children_counter - 1]);
}

static int	handle_processes_bonus(t_list *processes, t_prompt *prompt)
{
	int		children_counter;
	pid_t	pidc;
	pid_t	*pidc_array;

	pidc = 1;
	children_counter = 0;
	pidc_array = malloc(sizeof(pid_t) * prompt->number_of_processes);
	if (pidc_array == NULL)
		error_message("Error: Memory allocation failed");
	while (children_counter < prompt->number_of_processes)
	{
		pidc = fork();
		if (pidc == -1)
			error_message(strerror(errno));
		else if (pidc == 0)
			handle_children(processes, prompt, children_counter);
		else
		{
			pidc_array[children_counter] = pidc;
			handle_parent(prompt, children_counter++);
		}
		processes = processes->next;
	}
	return (return_exit_status(prompt, pidc_array));
}

int	run_prompt(t_list *processes, t_list **env, t_list **export_list)
{
	t_prompt	*prompt;
	int			exit_status;

	prompt = NULL;
	exit_status = 0;
	prompt = init_prompt(processes, &(*env), &(*export_list));
	if (prompt->number_of_processes == 0)
		return (exit_status);
	init_heredocs(processes);
	if (prompt->number_of_processes == 1
		&& !((t_process *)processes->content)->command)
		{
			exit_status = handle_file_descriptors(processes);
			if(exit_status == -1)
				exit_status = 1;
		}
		
	else if (prompt->number_of_processes == 1
		&& is_built_in(((t_process *)processes->content)->command[0]))
		exit_status = lonesome_built_in(processes, &prompt);
	else
		exit_status = handle_processes_bonus(processes, prompt);
	free_prompt(prompt);
	return (exit_status);
}
