/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:43:09 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 11:25:04 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRUCTS_H
# define UTILS_STRUCTS_H

# include "./Libft/libft.h"

/* typedef enum e_File_Type
{
	INFILE = 0,
	HEREDOC = 1,
	TRUNCATE = 2,
	APPEND = 3,
	INVALID_REDIR = 4
}	t_FileType;

typedef struct s_redir
{
	char		*name;
	t_FileType	value;
}	t_redir;

typedef struct s_process
{
	t_list	*redirections;
	char	**command;
	int		fd_infile;
	int		fd_outfile;
	char	*heredoc;
}	t_process;
 */
typedef struct s_test
{
	int		**fd_pipe;
	int		number_of_processes;
	int		fd_std_in;
	int		fd_std_out;
	t_list	*env;
	t_list	*export_list;
}	t_test;

t_test	*init_test(t_list *processes, t_list **env, t_list **export_list);
t_list	*create_env_list(char **env);
void	free_t_test(t_test *test);
void	clean_up_processes_list(t_list *list);
char	**string_list_to_bidimensional_array(t_list *env);

#endif
