/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:10:07 by ozini             #+#    #+#             */
/*   Updated: 2024/05/10 17:29:07 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_heredoc_bonus.h"
#include "utils_error_messages.h"
#include "utils_structs.h"

char	*create_heredoc_filename(int here_doc_process_counter)
{
	char	*here_doc_process_counter_char;
	char	*here_doc_name;

	here_doc_name = malloc(sizeof(char) * 17);
	if (here_doc_name == NULL)
		error_message("Error: Memory allocation failed\n");
	ft_strlcpy(here_doc_name, "/tmp/here_doc_", 16);
	here_doc_process_counter_char = ft_itoa(here_doc_process_counter);
	if (here_doc_process_counter_char == NULL)
		error_message("Error: Memory allocation failed\n");
	ft_strlcat(here_doc_name, here_doc_process_counter_char, 16);
	free(here_doc_process_counter_char);
	here_doc_process_counter_char = NULL;
	return (here_doc_name);
}

int	create_heredoc_file(char *delimiter, char *here_doc_filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(here_doc_filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (0);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		ft_memset(buffer, 0, sizeof(buffer));
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			close(fd);
			unlink(here_doc_filename);
			//ft_putstr_fd("Error: read failed in heredoc", STDERR_FILENO);
			// /tmp/.heredocs
			return (0);
		}
		if (ft_strncmp(buffer, delimiter, ft_strlen(buffer) - 1) == 0)
			break ;
		ft_putstr_fd(buffer, fd);
	}
	close(fd);
	return (1);
}

int	handle_heredoc(t_list *list, t_list *redirect,
	int here_doc_process_counter)
{
	char	*here_doc_name;

	here_doc_name = NULL;
	if (!((t_process *)list->content)->heredoc)
		here_doc_name = create_heredoc_filename(here_doc_process_counter);
	if (create_heredoc_file(((t_redir *)redirect->content)->name,
			here_doc_name))
	{
		((t_process *)list->content)->heredoc = ft_strdup(here_doc_name);
		free(here_doc_name);
		here_doc_name = NULL;
		return (0);
	}
	else
	{
		perror("bash");
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
