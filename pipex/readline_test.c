/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:31:33 by ozini             #+#    #+#             */
/*   Updated: 2024/05/13 16:53:46 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "../built_in/built_in.h"
#include "utils_structs.h"
#include "utils_memory_management.h"
#include "utils_env_export_lists.h"
#include "./parser/minishell.h"
#include "pipex_bonus.h"

void ft_leaks()
{
	system("leaks -q minishell");
}
int	main(int argc, char **argv, char **env)
{
	char	cwd[1024];
	char	*input;
	t_list	*processes;
	t_list	*env_list;
	t_list	*export_list;
	int		exit_status;

	(void)argv;
	(void)argc;
	atexit(ft_leaks);
	exit_status = 0;
	getcwd(cwd, sizeof(cwd));
	env_list = create_env_list(env);
	export_list = create_env_list(env);
	while (1)
	{
		input = readline("Minishell$ ");
		if (ft_strlen(input))
		{
			add_history(input);
			processes = parser(input, env_list);
			exit_status = pipex(processes, &env_list, &export_list);
/* 			exit_status = check_ft(input);
			if (!exit_status)
			{
				processes = parser(input, env_list);
				exit_status = pipex(processes, &env_list, &export_list);
			} */
			free(input);
			clean_up_processes_list(processes);
			printf("exit_status: %d\n", exit_status);
		}
	}
	while (env_list != NULL)
	{
		free(env_list->content);
		free(env_list);
		env_list = env_list->next;
	}
	while (export_list != NULL)
	{
		free(export_list->content);
		free(export_list);
		export_list = export_list->next;
	}
	return (exit_status);
}
