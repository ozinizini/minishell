/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file_descriptors.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:52:10 by ozini             #+#    #+#             */
/*   Updated: 2024/04/29 12:55:25 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_FILE_DESCRIPTORS_H
# define UTILS_FILE_DESCRIPTORS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include <errno.h>
# include <string.h>
# include "utils_structs.h"

int	handle_file_descriptors(t_list *list);

#endif