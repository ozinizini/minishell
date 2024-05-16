/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:49:31 by ozini             #+#    #+#             */
/*   Updated: 2024/05/15 15:39:54 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	create_path(char *env, char *command, char *concatenated)
{
	char	**split_path;
	char	*path;
	int		i;

	i = 0;
	path = ft_substr(env, 5, ft_strlen(env) - 5);
	if (path == NULL)
		return (1);
	split_path = ft_split(path, ':');
	if (split_path == NULL)
		return (free(path), 1);
	while (split_path[i] != NULL)
	{
		ft_strlcat(concatenated, split_path[i], 100);
		ft_strlcat(concatenated, "/", 100);
		ft_strlcat(concatenated, command, 100);
		if (access(concatenated, F_OK) != -1)
			if (access(concatenated, R_OK) != -1)
				break ;
		concatenated[0] = '\0';
		i++;
	}
	free(path);
	free_2d_char_array(split_path);
	return (0);
}

static	int	path_env_exists(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*check_path(char *command, char **env)
{
	char	*concatenated;
	int		path_env_pos;

	path_env_pos = 0;
	concatenated = malloc(100 * sizeof(char));
	if (concatenated == NULL)
		return (NULL);
	concatenated[0] = '\0';
	path_env_pos = path_env_exists(env);
	if (!path_env_pos)
		return (free(concatenated), ft_strdup(command));
	if (access(command, F_OK) != -1)
	{
		if (access(command, R_OK) != -1)
			ft_strlcat(concatenated, command, 100);
	}
	else if (create_path(env[path_env_pos], command, concatenated) == 1)
		return (free(concatenated), NULL);
	else if (concatenated[0] == '\0')
		return (free(concatenated), ft_strdup(command));
	return (concatenated);
}
