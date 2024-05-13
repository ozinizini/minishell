/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_paths.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:32:51 by ozini             #+#    #+#             */
/*   Updated: 2024/05/13 15:24:22 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PATHS_H
# define UTILS_PATHS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"
# include <errno.h>
# include <string.h>

char	*check_path(char *command, char **env);

#endif