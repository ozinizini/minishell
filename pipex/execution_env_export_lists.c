/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_env_export_lists.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:46:54 by ozini             #+#    #+#             */
/*   Updated: 2024/05/17 10:41:54 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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

static void	start_shlvl(t_list **list)
{
	t_list	*node;

	node = NULL;
	node = set_shlvl("SHLVL=1", 0);
	ft_lstadd_back(&(*list), node);
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
		if (!(ft_strncmp("SHLVL=", env[i], 6)))
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
		start_shlvl(&list);
	return (list);
}

void	clean_up_env_export_list(t_list *env_list, t_list *export_list)
{
	t_list	*temp;

	temp = NULL;
	while (env_list != NULL)
	{
		temp = env_list;
		env_list = env_list->next;
		free(temp->content);
		free(temp);
	}
	while (export_list != NULL)
	{
		temp = export_list;
		export_list = export_list->next;
		free(temp->content);
		free(temp);
	}
}
