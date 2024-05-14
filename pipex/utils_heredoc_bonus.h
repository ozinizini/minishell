/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:10:47 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 10:49:23 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HEREDOC_BONUS_H
# define UTILS_HEREDOC_BONUS_H

# define BUFFER_SIZE 1024

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <errno.h>
# include <string.h>

int		handle_heredoc(t_list *list, t_list *redirect,
			int here_doc_process_counter);
void	handle_infile(t_list *list);
void	init_heredocs(t_list *list);

#endif