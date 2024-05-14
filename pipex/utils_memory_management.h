/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory_management.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:40:55 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 14:37:28 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MEMORY_MANAGEMENT_H
# define UTILS_MEMORY_MANAGEMENT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"
# include <errno.h>
# include <string.h>

int		count_strings(char **str);
int		**init_2d_array(int rows, int cols);
void	free_2d_array_int(int **array, int rows);
void	free_2d_char_array(char **array);

#endif