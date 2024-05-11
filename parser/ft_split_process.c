/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:07:02 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/09 14:07:04 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_start(char *s, size_t pos)
{
	size_t	i;

	i = 0;
	while (pos > 0)
	{
		while (s[i] != '|' && s[i] != '\0')
		{
			if (s[i] == '\'' || s[i] == '\"')
				i = skip_all_quotes(s, i);
			else
				i++;
		}
		pos--;
		i++;
	}
	return (i);
}

static size_t	get_len(char *s)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		i = skip_all_quotes(s, i);
		if (s[i] == '|')
			len++;
		i++;
	}
	if (!s[i])
		len++;
	return (len);
}

static char	*get_str(char *s, size_t pos)
{
	size_t	i;
	size_t	start;
	char	*str;

	i = get_start(s, pos);
	start = i;
	while (s[i] != '|' && s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '"')
			i = skip_all_quotes(s, i);
		else
			i++;
	}
	while (s[start] == ' ')
		start++;
	while (s[i - 1] == ' ' && i > start)
		i--;
	str = ft_substr(s, start, i - start);
	return (str);
}

static void	free_split(char **split, size_t i)
{
	while (i-- > 0)
	{
		if (split[i])
			free(split[i]);
	}
	free(split);
	return ;
}

char	**ft_split_process(char *s)
{
	char	**split;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = get_len(s);
	split = malloc((len + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		split[i] = get_str(s, i);
		if (split[i] == NULL)
		{
			free_split(split, i);
			return (NULL);
		}
		i++;
	}
	split[len] = NULL;
	return (split);
}
