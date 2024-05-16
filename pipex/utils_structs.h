/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:43:09 by ozini             #+#    #+#             */
/*   Updated: 2024/05/16 09:45:44 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRUCTS_H
# define UTILS_STRUCTS_H

# include "./Libft/libft.h"

typedef struct s_prompt
{
	int		**fd_pipe;
	int		number_of_processes;
	int		fd_std_in;
	int		fd_std_out;
	t_list	**env;
	t_list	**export_list;
}	t_prompt;

#endif
