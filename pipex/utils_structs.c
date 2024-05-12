/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:03:10 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 18:03:35 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_structs.h"
#include "utils_error_messages.h"
#include "../built_in/built_in.h"
#include "utils_memory_management.h"
#include "./parser/minishell.h"

static t_list	*set_shlvl(char *old_shlvl, int shlvl_exists)
{
	char	*shlvl;
	long	shlvl_value;
	char	*shlvl_value_char;
	char	*new_shell_level_value;
	t_list	*node;

	node = NULL;
	shlvl = strnstr(old_shlvl, "=", ft_strlen(old_shlvl));
	shlvl++;
	shlvl_value = ft_atoi(shlvl);
	shlvl_value++;
	if (shlvl_exists)
		shlvl_value_char = ft_itoa(shlvl_value);
	else
		shlvl_value_char = ft_itoa(1);
	new_shell_level_value = ft_strjoin("SHLVL=", shlvl_value_char);
	node = ft_lstnew_string(new_shell_level_value);
	free(shlvl_value_char);
	free(new_shell_level_value);
	return (node);
}

t_list	*create_env_list(char **env)
{
	t_list	*node;
	t_list	*list;
	int		shlvl_exists;
	int		i;

	shlvl_exists = 0;
	i = 0;
	list = NULL;
	node = NULL;
	while (env[i] != NULL)
	{
		if (!(strncmp("SHLVL=", env[i], 6)))
		{
			shlvl_exists = 1;
			node = set_shlvl(env[i], 1);
		}
		else
			node = ft_lstnew_string((env[i]));
		ft_lstadd_back(&list, node);
		i++;
	}
	if (!shlvl_exists)
	{
		node = set_shlvl("SHLVL=1", 0);
		ft_lstadd_back(&list, node);
	}
	return (list);
}

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

t_test	*init_test(t_list *processes, t_list **env, t_list **export_list)
{
	t_test	*test;

	test = malloc(sizeof(t_test));
	if (test == NULL)
		error_message("Error: Memory allocation failed");
	test->fd_std_in = dup(STDIN_FILENO);
	test->fd_std_out = dup(STDOUT_FILENO);
	test->fd_pipe = NULL;
	test->number_of_processes = ft_lstsize(processes);
	test->env = *env;
	test->export_list = *export_list;
	return (test);
}

void	free_t_test(t_test *test)
{
	if (test->number_of_processes - 1 > 0)
		free_2d_array_int(test->fd_pipe, test->number_of_processes - 1);
	close(test->fd_std_in);
	close(test->fd_std_out);
/* 	while (test->env != NULL)
	{
		free(test->env->content);
		test->env = test->env->next;
	} */
	free(test);
}

void	clean_up_processes_list(t_list *list)
{
	t_process	*process;
	t_list		*redirec_list;
	t_redir		*redirec;

	while (list != NULL)
	{
		process = (t_process *)list->content;
		free_2d_char_array(process->command);
		if (process->heredoc)
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
