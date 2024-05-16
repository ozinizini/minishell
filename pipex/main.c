/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:31:33 by ozini             #+#    #+#             */
/*   Updated: 2024/05/16 11:16:29 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "./Libft/libft.h"
#include "./built_in/built_in.h"
#include "execute.h"
#include "utils_structs.h"
#include "./parser/minishell.h"


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
	clean_up_env_export_list(env_list, export_list);
	return (exit_status);
}
