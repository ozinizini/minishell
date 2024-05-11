/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:36:14 by ozini             #+#    #+#             */
/*   Updated: 2024/05/10 17:42:19 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_memory_management.h"

int	count_strings(char **str)
{
	int	count;

	count = 0;
	while (str[count] != NULL)
	{
		count++;
	}
	return (count);
}

int	**init_2d_array(int rows, int cols)
{
	int	**fd_pipe;
	int	i;

	fd_pipe = malloc (rows * sizeof(int *));
	if (fd_pipe == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		fd_pipe[i] = malloc(cols * sizeof(int));
		if (fd_pipe[i] == NULL)
			return (NULL);
		i++;
	}
	return (fd_pipe);
}

void	free_2d_array_int(int **array, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_2d_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
