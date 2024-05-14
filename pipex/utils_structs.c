/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:03:10 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 20:42:04 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	**string_list_to_bidimensional_array(t_list *env)
{
	char	**env_variables;
	int		i;

	env_variables = NULL;
	i = 0;
	env_variables = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
	if (env_variables == NULL)
		return (NULL);
	while (env != NULL)
	{
		env_variables[i] = malloc(sizeof(char)
				* (ft_strlen((const char *)env->content) + 1));
		if (env_variables[i] == NULL)
		{
			free_2d_char_array(env_variables);
			return (NULL);
		}
		ft_strlcat(env_variables[i], (const char *)env->content,
			ft_strlen((const char *)env->content) + 1);
		i++;
		env = env -> next;
	}
	env_variables[i] = NULL;
	return (env_variables);
}

t_prompt	*init_prompt(t_list *processes, t_list **env, t_list **export_list)
{
	t_prompt	*prompt;

	prompt = malloc(sizeof(t_prompt));
	if (prompt == NULL)
		error_message("Error: Memory allocation failed");
	prompt->fd_std_in = dup(STDIN_FILENO);
	prompt->fd_std_out = dup(STDOUT_FILENO);
	prompt->fd_pipe = NULL;
	prompt->number_of_processes = ft_lstsize(processes);
	if (prompt->number_of_processes - 1 > 0)
	{
		prompt->fd_pipe = init_2d_array(prompt->number_of_processes - 1, 2);
		if (prompt->fd_pipe == NULL)
			error_message("Error: Memory allocation failed");
		if (pipe(prompt->fd_pipe[0]) == -1)
		{
			free_2d_array_int(prompt->fd_pipe, prompt->number_of_processes - 1);
			error_message(strerror(errno));
		}
	}
	prompt->env = *env;
	prompt->export_list = *export_list;
	return (prompt);
}

void	free_prompt(t_prompt *prompt)
{
	if (prompt->number_of_processes - 1 > 0)
		free_2d_array_int(prompt->fd_pipe, prompt->number_of_processes - 1);
	close(prompt->fd_std_in);
	close(prompt->fd_std_out);
	free(prompt);
}

void	clean_up_processes_list(t_list *list, char **input)
{
	t_process	*process;
	t_list		*redirec_list;
	t_redir		*redirec;

	(void)input;
	process = NULL;
	redirec_list = NULL;
	redirec = NULL;
	while (list != NULL)
	{
		process = (t_process *)list->content;
		free_2d_char_array(process->command);
		free(process->heredoc);
		redirec_list = process->redirections;
		while (redirec_list != NULL)
		{
			redirec = (t_redir *)redirec_list->content;
			free(redirec->name);
			free(redirec);
			free(redirec_list);
			redirec_list = redirec_list->next;
		}
		free(process);
		free(list);
		list = list ->next;
	}
}
