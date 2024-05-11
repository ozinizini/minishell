/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:56:03 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/10 17:33:28 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_list	*parser(char *line, t_list *env)
{
	char	**str_process;
	t_list	*process_list;

	process_list = NULL;
	str_process = NULL;
	str_process = ft_split_process(line);
	get_process_list(str_process, &process_list);
	parse_list(process_list, env);
	//free(line);
	return (process_list);
}
