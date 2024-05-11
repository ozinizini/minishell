/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file_descriptors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:51:26 by ozini             #+#    #+#             */
/*   Updated: 2024/04/29 13:03:19 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_file_descriptors.h"
#include "utils_error_messages.h"

static void	handle_fd_infile(t_list *list, t_list *redirections)
{
	if (((t_process *)list->content)->fd_infile)
		close(((t_process *)list->content)->fd_infile);
	((t_process *)list->content)->fd_infile = open(((t_redir *)
				redirections->content)->name, O_RDONLY);
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

int	handle_file_descriptors(t_list *list)
{
	t_list	*redirections;

	redirections = ((t_process *)list->content)->redirections;
	while (redirections != NULL)
	{
		if (((t_redir *)redirections->content)->value == INFILE)
			handle_fd_infile(list, redirections);
		else if (((t_redir *)redirections->content)->value == TRUNCATE)
			handle_fd_outfile_truncate(list, redirections);
		else if (((t_redir *)redirections->content)->value == APPEND)
			handle_fd_outfile_append(list, redirections);
		if (((t_process *)list->content)->fd_infile == -1)
		{
			if (!((t_process *)list->content)->fd_outfile)
				close(((t_process *)list->content)->fd_outfile);
			bash_error_message(strerror(errno),
				((t_redir *)redirections->content)->name);
			return (-1);
		}
		redirections = redirections->next;
	}
	return (0);
}
