/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:17:35 by ozini             #+#    #+#             */
/*   Updated: 2024/05/08 18:09:44 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	env_variable_exists(t_list *env, char *export_variable)
{
	int		list_pos;
	char	*substr;
	char	*substr_2;

	list_pos = 0;
	substr = variable_name(export_variable);
	if (substr == NULL)
		return (error_message_return
			("Memory allocation failed\n", -1));
	while (env != NULL)
	{
		list_pos++;
		substr_2 = variable_name((char *)env->content);
		if (substr_2 == NULL)
			return (free(substr),
				error_message_return("Memory allocation failed\n", -1));
		if (ft_strlen(substr) == ft_strlen(substr_2))
			if (!(ft_strncmp((const char *)substr_2,
						(const char *)substr, ft_strlen(substr))))
				return (free(substr), free(substr_2), list_pos);
		free(substr_2);
		env = env ->next;
	}
	free(substr);
	return (0);
}

static	void	delete_first_node(t_list **list)
{
	t_list	*temp;

	temp = *list;
	(*list) = (*list)->next;
	if (temp->content)
		free(temp->content);
	if (temp)
		free(temp);
}

static	void	delete_node_other_than_first(t_list **list, int node_position)
{
	t_list	*temp;
	int		node_index;

	temp = *list;
	node_index = 1;
	while (node_index < node_position)
	{
		if (node_index == node_position - 1)
		{
			free(temp->next->content);
			free(temp->next);
			temp->next = temp->next->next;
			temp = temp->next;
		}
		else
			temp = (temp->next);
		node_index++;
	}
}

void	ft_delete_node(t_list **list, int node_position)
{
	if (node_position == 1)
		delete_first_node(list);
	else
		delete_node_other_than_first(list, node_position);
}

void	sort_list(t_list *list)
{
	const char	*first_string;
	const char	*second_string;
	t_list		*temp;
	void		*swap;

	first_string = NULL;
	second_string = NULL;
	temp = list;
	while (temp->next != NULL)
	{
		first_string = (const char *)temp->content;
		second_string = (const char *)temp->next->content;
		if (ft_strcmp(first_string, second_string) > 0)
		{
			swap = temp->content;
			temp->content = temp->next->content;
			temp->next->content = swap;
			temp = list;
		}
		else
			temp = temp->next;
	}
}
