/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_run_built_in.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:38:40 by ozini             #+#    #+#             */
/*   Updated: 2024/05/11 11:42:38 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RUN_BUILT_IN_H
# define UTILS_RUN_BUILT_IN_H

# include "utils_structs.h"
# include "../built_in/built_in.h"
# include "utils_memory_management.h"

int	is_built_in( char *command);
int	run_built_in(char **command, t_test **test);

#endif