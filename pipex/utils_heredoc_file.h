/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc_file.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:44:01 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 10:50:14 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HEREDOC_FILE_H
# define UTILS_HEREDOC_FILE_H

# define BUFFER_SIZE 1024

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <errno.h>
# include <string.h>

char	*create_heredoc_filename(int here_doc_process_counter);
int		create_heredoc_file(char *delimiter, char *here_doc_filename);

#endif