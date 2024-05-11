/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:00:05 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/08 16:52:54 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	clean_double_quotes(char *line, size_t i)
{
	ft_memmove(line + i, line + i + 1, ft_strlen(line + i + 1) + 1);
	while (line[i] != '\"')
		i++;
	ft_memmove(line + i, line + i + 1, ft_strlen(line + i + 1) + 1);
	return (i);
}

size_t	clean_single_quotes(char *line, size_t i)
{
	ft_memmove(line + i, line + i + 1, ft_strlen(line + i + 1) + 1);
	while (line[i] != '\'')
		i++;
	ft_memmove(line + i, line + i + 1, ft_strlen(line + i + 1) + 1);
	return (i);
}

char	*ft_clean_quotes(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			i = clean_single_quotes(line, i);
		else if (line[i] == '\"')
			i = clean_double_quotes(line, i);
		else if (line[i] != '\'' && line[i] != '\"')
			i++;
	}
	return (line);
}
