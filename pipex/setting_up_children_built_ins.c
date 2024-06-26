/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_up_children_built_ins.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:27:28 by ozini             #+#    #+#             */
/*   Updated: 2024/05/17 17:29:03 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	handle_dups(t_list *process, int *fd_pipe, int *fd_pipe2)
{
	if ((((t_process *)process->content)->heredoc))
		((t_process *)process->content)->fd_infile = open((((t_process *)
						process->content)->heredoc), O_RDONLY);
	if (((t_process *)process->content)->fd_infile)
	{
		dup2(((t_process *)process->content)->fd_infile, STDIN_FILENO);
		close(((t_process *)process->content)->fd_infile);
	}
	else if (fd_pipe)
	{
		dup2(fd_pipe[0], STDIN_FILENO);
		close(fd_pipe[0]);
	}
	if (((t_process *)process->content)->fd_outfile)
	{
		dup2(((t_process *)process->content)->fd_outfile, STDOUT_FILENO);
		close(((t_process *)process->content)->fd_outfile);
	}
	else if (fd_pipe2)
	{
		dup2(fd_pipe2[1], STDOUT_FILENO);
		close(fd_pipe2[1]);
	}
}

int	lonesome_built_in(t_list *process, t_prompt **prompt)
{
	int	fd_infile;
	int	exit_status;

	exit_status = 1;
	if (((t_process *)process->content)->fd_infile == -1)
		fd_infile = -1;
	else
		fd_infile = handle_file_descriptors(process);
	if (fd_infile != -1)
	{
		handle_dups(process, NULL, NULL);
		if ((((t_process *)process->content)->heredoc))
			unlink((((t_process *)process->content)->heredoc));
		exit_status = (run_built_in(((t_process *)process->content)
					->command, &(*prompt)));
		dup2((*prompt)->fd_std_in, STDIN_FILENO);
		dup2((*prompt)->fd_std_out, STDOUT_FILENO);
	}
	close_file_descriptors(process);
	return (exit_status);
}

void	infile_child_process_bonus(t_list *process, t_prompt *prompt,
	int **fd_pipe)
{
	int	fd_infile;

	if (fd_pipe)
		close(fd_pipe[0][0]);
	if (((t_process *)process->content)->fd_infile == -1)
		fd_infile = -1;
	else
		fd_infile = handle_file_descriptors(process);
	if (fd_infile != -1)
	{
		if (fd_pipe)
			handle_dups(process, NULL, fd_pipe[0]);
		else
			handle_dups(process, NULL, NULL);
		if ((((t_process *)process->content)->heredoc))
			unlink((((t_process *)process->content)->heredoc));
		if (!(((t_process *)process->content)->command))
			exit(EXIT_SUCCESS);
		exec_first_child(process, prompt, fd_pipe);
	}
	else if (fd_pipe)
		close(fd_pipe[0][1]);
	if (errno == EACCES)
		exit(126);
	exit(EXIT_FAILURE);
}

void	intermediate_children_process(t_list *process, t_prompt *prompt,
	int *fd_pipe, int *fd_pipe2)
{
	int	fd_infile;

	if (((t_process *)process->content)->fd_infile == -1)
		fd_infile = -1;
	else
		fd_infile = handle_file_descriptors(process);
	if (fd_infile != -1)
	{
		handle_dups(process, fd_pipe, fd_pipe2);
		if ((((t_process *)process->content)->heredoc))
			unlink((((t_process *)process->content)->heredoc));
		if (!(((t_process *)process->content)->command))
			exit(EXIT_SUCCESS);
		exec_intermediate_child(process, prompt, fd_pipe, fd_pipe2);
	}
	else
	{
		close(fd_pipe2[0]);
		close(fd_pipe[0]);
		close(fd_pipe2[1]);
	}
	if (errno == EACCES)
		exit(126);
	exit(EXIT_FAILURE);
}

void	outfile_child_process_bonus(t_list *process,
	t_prompt *prompt, int *fd_pipe)
{
	int	fd_infile;

	if (((t_process *)process->content)->fd_infile == -1)
		fd_infile = -1;
	else
		fd_infile = handle_file_descriptors(process);
	if (fd_infile != -1)
	{
		handle_dups(process, fd_pipe, NULL);
		if ((((t_process *)process->content)->heredoc))
			unlink((((t_process *)process->content)->heredoc));
		if (!(((t_process *)process->content)->command))
			exit(EXIT_SUCCESS);
		exec_last_child(process, prompt, fd_pipe);
	}
	else
		close(fd_pipe[0]);
	if (errno == EACCES)
		exit(126);
	exit(EXIT_FAILURE);
}
