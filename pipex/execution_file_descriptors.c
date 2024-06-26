/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_file_descriptors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:51:26 by ozini             #+#    #+#             */
/*   Updated: 2024/05/18 17:14:56 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	handle_fd_infile(t_list *list, t_list *redirections)
{
	if (((t_process *)list->content)->fd_infile)
		close(((t_process *)list->content)->fd_infile);
	((t_process *)list->content)->fd_infile = open(((t_redir *)
				redirections->content)->name, O_RDONLY);
	if (((t_process *)list->content)->fd_infile == -1)
		return ;
	else if (((t_process *)list->content)->heredoc)
	{
		close(((t_process *)list->content)->fd_infile);
		((t_process *)list->content)->fd_infile = 0;
	}
}

static void	handle_fd_outfile_truncate(t_list *list, t_list *redirections)
{
	if (((t_process *)list->content)->fd_outfile)
		close(((t_process *)list->content)->fd_outfile);
	((t_process *)list->content)->fd_outfile = open(((t_redir *)
				redirections->content)->name,
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

static void	handle_fd_outfile_append(t_list *list, t_list *redirections)
{
	if (((t_process *)list->content)->fd_outfile)
		close(((t_process *)list->content)->fd_outfile);
	((t_process *)list->content)->fd_outfile = open(((t_redir *)
				redirections->content)->name,
			O_WRONLY | O_CREAT | O_APPEND, 0777);
}

static	int	fd_error(t_list *list, t_list *redirections)
{
	if (((t_process *)list->content)->fd_infile == -1
		|| ((t_process *)list->content)->fd_outfile == -1)
	{
		if (((t_process *)list->content)->fd_outfile != -1
			&& ((t_process *)list->content)->fd_outfile > 2)
			close(((t_process *)list->content)->fd_outfile);
		if (((t_process *)list->content)->fd_infile != -1
			&& ((t_process *)list->content)->fd_infile > 2)
			close(((t_process *)list->content)->fd_infile);
		if ((((t_process *)list->content)->heredoc))
			unlink((((t_process *)list->content)->heredoc));
		bash_error_message(strerror(errno),
			((t_redir *)redirections->content)->name);
		return (1);
	}
	else
		return (0);
}

int	handle_file_descriptors(t_list *list)
{
	t_list	*redirections;

	redirections = NULL;
	redirections = ((t_process *)list->content)->redirections;
	while (redirections != NULL)
	{
		if (((t_redir *)redirections->content)->value == INFILE)
			handle_fd_infile(list, redirections);
		else if (((t_redir *)redirections->content)->value == TRUNCATE)
			handle_fd_outfile_truncate(list, redirections);
		else if (((t_redir *)redirections->content)->value == APPEND)
			handle_fd_outfile_append(list, redirections);
		if (fd_error(list, redirections))
			return (-1);
		redirections = redirections->next;
	}
	return (0);
}
