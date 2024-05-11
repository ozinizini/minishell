/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:02:35 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/10 17:37:30 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_File_Type	get_outfile(char *ptr)
{
	t_File_Type	redir_type;

	redir_type = TRUNCATE;
	if (ptr[1] == '<')
		redir_type = INVALID_REDIR;
	if (ptr[1] == '>')
	{
		redir_type = APPEND;
		if (ptr[2] == '<' || ptr[2] == '>')
			redir_type = INVALID_REDIR;
	}
	return (redir_type);
}

t_File_Type	get_infile(char *ptr)
{
	t_File_Type	redir_type;

	redir_type = INFILE;
	if (ptr[1] == '>')
		redir_type = INVALID_REDIR;
	if (ptr[1] == '<')
	{
		redir_type = HEREDOC;
		if (ptr[2] == '<' || ptr[2] == '>')
			redir_type = INVALID_REDIR;
	}
	return (redir_type);
}

t_File_Type	get_redir_type(char *ptr)
{
	t_File_Type	redir_type;

	redir_type = INVALID_REDIR;
	if (ptr[0] == '<')
		redir_type = get_infile(ptr);
	else if (ptr[0] == '>')
		redir_type = get_outfile(ptr);
	return (redir_type);
}
