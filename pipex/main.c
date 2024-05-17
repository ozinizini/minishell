/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:31:33 by ozini             #+#    #+#             */
/*   Updated: 2024/05/17 13:57:54 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "./Libft/libft.h"
#include "./built_in/built_in.h"
#include "execute.h"
#include "utils_structs.h"
#include "./parser/minishell.h"

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	initialize_minishell(int exit_status,
	t_list *env_list, t_list *export_list)
{
	char	*input;
	t_list	*processes;

	processes = NULL;
	input = NULL;
	while (1)
	{
		input = readline("Minishell$ ");
		if (input && ft_strlen(input))
		{
			add_history(input);
			if (ft_check_syntax(input))
				exit_status = 258;
			else
			{
				processes = parser(input, env_list, exit_status);
				exit_status = run_prompt(processes, &env_list, &export_list);
			}
			clean_up_processes_list(processes);
			processes = NULL;
		}
		free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	*env_list;
	t_list	*export_list;
	int		exit_status;

	(void)argv;
	(void)argc;
	atexit(ft_leaks);
	exit_status = 0;
	env_list = create_env_list(env);
	export_list = create_env_list(env);
	initialize_minishell(exit_status, env_list, export_list);
	clean_up_env_export_list(env_list, export_list);
	return (exit_status);
}
