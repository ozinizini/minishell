/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_processes_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:26:00 by ozini             #+#    #+#             */
/*   Updated: 2024/05/10 17:20:34 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PROCESSES_BONUS_H
# define UTILS_PROCESSES_BONUS_H

# define BUFFER_SIZE 1024

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <errno.h>
# include <string.h>
# include "utils_structs.h"

int		lonesome_built_in(t_list *process, t_test **test);
void	infile_child_process_bonus(t_list *process, t_test *test,
			int **fd_pipe);
void	intermediate_children_process(t_list *process, t_test *test,
			int *fd_pipe, int *fd_pipe2);
void	outfile_child_process_bonus(t_list *process,
			t_test *test, int *fd_pipe);

#endif