/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:31:33 by ozini             #+#    #+#             */
/*   Updated: 2024/05/17 16:23:24 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./Libft/libft.h"
#include "./built_in/built_in.h"
#include "execute.h"
#include "utils_structs.h"
#include "./parser/minishell.h"

int	g_sig;

int	update_exit_status(int exit_status)
{
	if (g_sig)
	{
		exit_status = g_sig;
		g_sig = 0;
	}
	return (exit_status);
}

char	*get_input(void)
{
	char	*input;

	input = NULL;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, int_handler);
	set_echoctl(0, 0);
	input = readline("Minishell$ ");
	set_echoctl(0, 1);
	return (input);
}

void	prepare_exe_sig(char *input)
{
	add_history(input);
	signal(SIGQUIT, quit_handler);
	signal(SIGINT, int_exe_sig);
}

int	initialize_minishell(int exit_status,
	t_list *env_list, t_list *export_list)
{
	char	*input;
	t_list	*processes;

	processes = NULL;
	input = NULL;
	input = get_input();
	exit_status = update_exit_status(exit_status);
	if (!input)
		exit(exit_status);
	if (ft_strlen(input))
	{
		prepare_exe_sig(input);
		if (ft_check_syntax(input))
			exit_status = 258;
		else
		{
			processes = parser(input, env_list, exit_status);
			exit_status = run_prompt(processes, &env_list, &export_list);
		}
		clean_up_processes_list(processes);
	}
	free(input);
	return (exit_status);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*env_list;
	t_list	*export_list;
	int		exit_status;

	(void)argv;
	(void)argc;
	exit_status = 0;
	env_list = create_env_list(env);
	export_list = create_env_list(env);
	while (1)
		exit_status = initialize_minishell(exit_status, env_list, export_list);
	clean_up_env_export_list(env_list, export_list);
	return (exit_status);
}
