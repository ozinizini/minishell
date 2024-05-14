/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:56:03 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/14 15:34:59 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_var(t_list **env, int var)
{
	char	*exit_status;
	t_list	*exit_node;
	char	*join;

	exit_status = NULL;
	exit_status = ft_itoa(var);
	join = ft_strjoin("?=", exit_status);
	exit_node = ft_lstnew(join);
	ft_lstadd_front(env, exit_node);
	free(exit_status);
}

static void	free_var(t_list **env)
{
	t_list	*exit_node;

	exit_node = NULL;
	exit_node = *env;
	*env = exit_node->next;
	free(exit_node->content);
	free(exit_node);
}

void	get_process_list(char **str_process, t_list **list)
{
	size_t	i;
	t_list	*new_node;

	i = 0;
	while (str_process[i])
	{
		new_node = ft_lstnew(str_process[i]);
		ft_lstadd_back(list, new_node);
		i++;
	}
	free(str_process);
}

t_list	*parser(char *line, t_list *env, int var)
{
	char	**str_process;
	t_list	*process_list;

	process_list = NULL;
	str_process = NULL;
	add_var(&env, var);
	str_process = ft_split_process(line);
	get_process_list(str_process, &process_list);
	parse_list(process_list, env);
	free_var(&env);
	return (process_list);
}
