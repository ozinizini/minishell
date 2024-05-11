/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:49:31 by ozini             #+#    #+#             */
/*   Updated: 2024/04/25 11:21:27 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_paths.h"
#include "utils_error_messages.h"
#include "utils_memory_management.h"

int	create_path(char *env, char *command, char *concatenated)
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

char	*check_path(char *command, char **env)
{
	int		i;
	char	*concatenated;

	concatenated = malloc(100 * sizeof(char));
	if (concatenated == NULL)
		return (NULL);
	concatenated[0] = '\0';
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (access(command, F_OK) != -1)
	{
		if (access(command, R_OK) != -1)
			ft_strlcat(concatenated, command, 100);
	}
	else if (create_path(env[i], command, concatenated) == 1)
		return (free(concatenated), NULL);
	else if ((create_path(env[i], command, concatenated) == 0)
		&& concatenated[0] == '\0')
		return (free(concatenated), ft_strdup(command));
	return (concatenated);
}
