/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_export_lists.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:47:09 by ozini             #+#    #+#             */
/*   Updated: 2024/05/13 16:49:31 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_ENV_EXPORT_LISTS_H
# define UTILS_ENV_EXPORT_LISTS_H

#include "utils_structs.h"
#include "utils_error_messages.h"
#include "../built_in/built_in.h"
#include "utils_memory_management.h"
#include "./parser/minishell.h"

t_list	*create_env_list(char **env);

#endif