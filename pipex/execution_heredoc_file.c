/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_heredoc_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:43:19 by ozini             #+#    #+#             */
/*   Updated: 2024/05/18 14:39:57 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

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

static	int	delimiter_vs_input(char *delimiter, char *buffer)
{
	int	comparison_len;

	comparison_len = ft_strlen(delimiter);
	if (ft_strlen(buffer) - 1 > ft_strlen(delimiter))
		comparison_len = ft_strlen(buffer) - 1;
	if (ft_strncmp(buffer, delimiter, comparison_len) == 0)
		return (1);
	else
		return (0);
}

static	int	write_to_heredoc(char *delimiter,
	char *here_doc_filename, char *buffer, int fd)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		ft_memset(buffer, 0, sizeof(buffer));
		set_echoctl(0, 0);
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		set_echoctl(0, 1);
		if (bytes_read == -1)
		{
			if (errno == EINTR)
				return (-1);
			return (unlink(here_doc_filename));
		}
		if (delimiter_vs_input(delimiter, buffer))
			break ;
		ft_putstr_fd(buffer, fd);
	}
	return (1);
}

int	create_heredoc_file(char *delimiter, char *here_doc_filename)
{
	struct sigaction	sa;
	int					fd;
	char				buffer[BUFFER_SIZE];
	int					write_status;

	sa.sa_handler = int_heredoc;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	fd = open(here_doc_filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (0);
	write_status = write_to_heredoc(delimiter, here_doc_filename, buffer, fd);
	close(fd);
	return (write_status);
}
