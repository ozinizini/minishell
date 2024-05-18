/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_heredoc_management.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:10:07 by ozini             #+#    #+#             */
/*   Updated: 2024/05/18 15:09:53 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	clean_up_heredoc_sigint(void)
{
	DIR				*dir;
	struct dirent	*entry;
	char			filename[1024];

	ft_strlcat(filename, "/tmp/", 1024);
	dir = opendir("/tmp");
	if (dir == NULL)
	{
		perror("Unable to open directory");
		return (1);
	}
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (!ft_strncmp(entry->d_name, "here_doc_", 9))
		{
			ft_strlcat(filename, entry->d_name, 1024);
			unlink(filename);
			filename[0] = '\0';
			ft_strlcat(filename, "/tmp/", 1024);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (1);
}

static int	handle_heredoc(t_list *list, t_list *redirect,
			int here_doc_process_counter)
{
	char	*here_doc_name;
	int		hd_status;

	here_doc_name = NULL;
	here_doc_name = create_heredoc_filename(here_doc_process_counter);
	hd_status = create_heredoc_file(((t_redir *)
				redirect->content)->name, here_doc_name);
	if (hd_status == 1)
	{
		free(((t_process *)list->content)->heredoc);
		((t_process *)list->content)->heredoc = ft_strdup(here_doc_name);
		free(here_doc_name);
		here_doc_name = NULL;
		return (0);
	}
	else if (hd_status == 0)
	{
		perror("Minishell");
		((t_process *)list->content)->fd_infile = -1;
		free(here_doc_name);
		here_doc_name = NULL;
		return (1);
	}
	else
		return (clean_up_heredoc_sigint());
}

static void	handle_infile(t_list *list)
{
	if (((t_process *)list->content)->heredoc)
	{
		unlink(((t_process *)list->content)->heredoc);
		free(((t_process *)list->content)->heredoc);
		((t_process *)list->content)->heredoc = NULL;
	}
}

void	init_heredocs(t_list *list)
{
	t_list	*redirect;
	int		here_doc_process_counter;

	redirect = NULL;
	here_doc_process_counter = 0;
	while (list != NULL && !g_sig)
	{
		here_doc_process_counter++;
		redirect = ((t_process *)list->content)->redirections;
		while (redirect != NULL)
		{
			if (((t_redir *)redirect->content)->value == HEREDOC)
			{
				if (handle_heredoc(list, redirect, here_doc_process_counter))
					break ;
			}
			else if (((t_redir *)redirect->content)->value == INFILE)
				handle_infile(list);
			redirect = redirect->next;
		}
		list = list->next;
	}
}
