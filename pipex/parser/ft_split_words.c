/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:10:23 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/18 19:30:14 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_start(char *s, size_t pos)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	while (pos > 0)
	{
		while (s[i] != ' ' && s[i] != '\0')
		{
			if (s[i] == '\'' || s[i] == '\"')
				i = skip_all_quotes(s, i);
			else
				i++;
		}
		while (s[i + 1] == ' ')
			i++;
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
	while (s[i] == ' ')
		i++;
	while (s[i])
	{
		i = skip_all_quotes(s, i);
		if (s[i] == ' ')
		{
			len++;
			while (s[i + 1] == ' ')
				i++;
		}
		i++;
	}
	if (!s[i] && s[i - 1] != ' ')
		len++;
	return (len);
}

static char	*get_str(char *s, size_t pos)
{
	size_t	i;
	size_t	start;
	char	*str;

	str = NULL;
	i = get_start(s, pos);
	start = i;
	while (s[i] != ' ' && s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '"')
			i = skip_all_quotes(s, i);
		else
			i++;
	}
	str = ft_substr(s, start, i - start);
	return (str);
}

static void	free_split(char **split, size_t i)
{
	while (i-- > 0)
	{
		if (split && split[i])
			free(split[i]);
	}
	free(split);
	return ;
}

char	**ft_split_words(char *s)
{
	char	**split;
	size_t	i;
	size_t	len;

	split = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!check_empty(s))
		return (NULL);
	len = get_len(s);
	split = malloc((len + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < len)
	{
		split[i] = get_str(s, i);
		if (split[i] == NULL)
			return (free_split(split, i), NULL);
		i++;
	}
	split[len] = NULL;
	return (split);
}
