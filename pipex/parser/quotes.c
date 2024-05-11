/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:54:25 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/08 16:54:36 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	skip_single_quotes(char *str, size_t i)
{
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
		i++;
	}
	if (str[i] == '\'')
		i = skip_single_quotes(str, i);
	return (i);
}

size_t	skip_double_quotes(char *str, size_t i)
{
	if (str[i] == '"')
	{
		i++;
		while (str[i] != '"')
			i++;
		i++;
	}
	if (str[i] == '"')
		i = skip_double_quotes(str, i);
	return (i);
}

size_t	skip_all_quotes(char *str, size_t i)
{
	i = skip_single_quotes(str, i);
	i = skip_double_quotes(str, i);
	if (str[i] == '\'' || str[i] == '"')
		i = skip_all_quotes(str, i);
	return (i);
}
