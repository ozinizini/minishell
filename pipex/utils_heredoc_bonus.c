/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:10:07 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 13:43:18 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_heredoc_bonus.h"
#include "utils_error_messages.h"
#include "./parser/minishell.h"
#include "utils_heredoc_file.h"

int	handle_heredoc(t_list *list, t_list *redirect,
	int here_doc_process_counter)
{
	char	*here_doc_name;

	here_doc_name = NULL;
	here_doc_name = create_heredoc_filename(here_doc_process_counter);
	if (create_heredoc_file(((t_redir *)redirect->content)->name,
			here_doc_name))
	{
		free(((t_process *)list->content)->heredoc);
		((t_process *)list->content)->heredoc = ft_strdup(here_doc_name);
		free(here_doc_name);
		here_doc_name = NULL;
		return (0);
	}
	else
	{
		perror("Minishell");
		((t_process *)list->content)->fd_infile = -1;
		free(here_doc_name);
		here_doc_name = NULL;
		return (1);
	}
}

void	handle_infile(t_list *list)
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
	while (list != NULL)
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
