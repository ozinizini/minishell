/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_run_built_in.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:38:40 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 14:46:45 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RUN_BUILT_IN_H
# define UTILS_RUN_BUILT_IN_H

# include "utils_structs.h"
# include "../built_in/built_in.h"
# include "utils_memory_management.h"

int	is_built_in( char *command);
int	run_built_in(char **command, t_prompt **prompt);

#endif