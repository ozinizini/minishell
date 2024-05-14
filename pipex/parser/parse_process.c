/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:39:24 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/14 19:06:24 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_process_struct(t_process *process)
{
	process->command = NULL;
	process->redirections = NULL;
	process->fd_infile = 0;
	process->fd_outfile = 0;
	process->heredoc = NULL;
}

t_process	*parse_process(void *str_process, t_list *env)
{
	t_process	*process;
	size_t		i;

	i = 0;
	process = malloc(sizeof(t_process));
	if (!process)
		return (NULL);
	str_process = (char *)str_process;
	init_process_struct(process);
	get_redir(str_process, process, env);
	str_process = expander(str_process, env);
	process->command = ft_split_words(str_process);
	free(str_process);
	if (!process->command[0])
	{
		free(process->command);
		process->command = NULL;
	}
	while (process->command && process->command[i])
	{
		process->command[i] = ft_clean_quotes(process->command[i]);
		i++;
	}
	return (process);
}

void	parse_list(t_list *process_list, t_list *env)
{
	if (process_list)
	{
		process_list->content
			= (void *)parse_process(process_list->content, env);
		parse_list(process_list->next, env);
	}
}
