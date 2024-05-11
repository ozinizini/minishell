/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_processes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:46:00 by ozini             #+#    #+#             */
/*   Updated: 2024/05/10 17:42:01 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PROCESSES_H
# define UTILS_PROCESSES_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"
# include <errno.h>
# include <string.h>
# include "utils_structs.h"

void	exec_first_child(t_list *list, t_test *test, int **fd_pipe);
void	exec_last_child(t_list *list, t_test *test, int *fd_pipe);
void	exec_intermediate_child(t_list *list, t_test *test,
			int *fd_pipe, int *fd_pipe2);

#endif