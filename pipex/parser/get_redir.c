/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:13:00 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/14 18:18:49 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clear_str(char *str_process, size_t i)
{
	size_t	dst;
	size_t	len;

	dst = i;
	while (str_process[i] == '>' || str_process[i] == '<')
		i++;
	while (str_process[i] == ' ')
		i++;
	while (str_process[i] && str_process[i] != ' '
		&& str_process[i] != '<' && str_process[i] != '>')
	{
		if (str_process[i] == '\'' || str_process[i] == '"')
			i = skip_all_quotes(str_process, i);
		else
			i++;
	}
	len = ft_strlen(str_process + i) + 1;
	ft_memmove(str_process + dst, str_process + i, len);
	return (str_process);
}

char	*get_file_str(char *redir_str)
{
	char	*file_str;
	size_t	i;
	size_t	start;

	i = 0;
	while (redir_str[i] == '>' || redir_str[i] == '<')
		i++;
	while (redir_str[i] == ' ')
		i++;
	start = i;
	while (redir_str[i] && redir_str[i] != ' '
		&& redir_str[i] != '<' && redir_str[i] != '>')
	{
		if (redir_str[i] == '\'' || redir_str[i] == '"')
			i = skip_all_quotes(redir_str, i);
		else
			i++;
	}
	i--;
	file_str = ft_substr(redir_str, start, i - start + 1);
	return (file_str);
}

t_redir	*split_redir(char *ptr)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->value = get_redir_type(ptr);
	redir->name = get_file_str(ptr);
	return (redir);
}

void	add_redir_list(char *ptr, t_process *process, t_list *env)
{
	t_list	*redir_list;
	t_redir	*redir;

	redir = split_redir(ptr);
	redir->name = expander(redir->name, env);
	redir->name = ft_clean_quotes(redir->name);
	redir_list = ft_lstnew(redir);
	ft_lstadd_back(&process->redirections, redir_list);
}

void	get_redir(char *str_process, t_process *process, t_list *env)
{
	size_t	i;

	i = 0;
	while (str_process[i])
	{
		i = skip_all_quotes(str_process, i);
		if (str_process[i] == '<' || str_process[i] == '>')
		{
			add_redir_list(str_process + i, process, env);
			str_process = clear_str(str_process, i);
			i = 0;
			continue ;
		}
		if (str_process[i])
			i++;
	}
}
