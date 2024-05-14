/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:20:09 by ozini             #+#    #+#             */
/*   Updated: 2024/05/14 14:58:55 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define BUFFER_SIZE 1024

# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include "./Libft/libft.h"
# include "./built_in/built_in.h"
# include "./parser/minishell.h"
# include "utils_structs.h"

//This function runs the prompt entered by the user
int		run_prompt(t_list *processes, t_list **env, t_list **export_list);

//This function handles the initialization of the list that is a copy
//of the environment variables (**env)
t_list	*create_env_list(char **env);

//Functions that handle the errors shown on the terminal
//The first one doesn't exit whereas the second, does
void	bash_error_message(char *error_description, char *source);
void	error_message(char *error_message);

//The following function handles all file descriptors in terms of
//the file descriptor of an infile redirection (which includes heredocs)
//and the file descriptor for an outfile redirection.

int	handle_file_descriptors(t_list *list);

//The following functions are responsible for creating all heredocs
//at once before running any command.

char	*create_heredoc_filename(int here_doc_process_counter);
int		create_heredoc_file(char *delimiter, char *here_doc_filename);
void	init_heredocs(t_list *list);

//Functions for the creation and initialization of 2D arrays

int		count_strings(char **str);
int		**init_2d_array(int rows, int cols);
void	free_2d_array_int(int **array, int rows);
void	free_2d_char_array(char **array);

// This function checks for the existence of the path of a command
// in the PATH environment variables.
char	*check_path(char *command, char **env);

//This functions are responsible for the execution of the children processes
//as well as a built_in function run in the parent process (minishell program).
int		is_built_in( char *command);
int		run_built_in(char **command, t_prompt **prompt);
int		lonesome_built_in(t_list *process, t_prompt **prompt);
void	infile_child_process_bonus(t_list *process, t_prompt *prompt,
			int **fd_pipe);
void	exec_first_child(t_list *list, t_prompt *prompt, int **fd_pipe);
void	intermediate_children_process(t_list *process, t_prompt *prompt,
			int *fd_pipe, int *fd_pipe2);
void	exec_intermediate_child(t_list *list, t_prompt *prompt,
			int *fd_pipe, int *fd_pipe2);
void	outfile_child_process_bonus(t_list *process,
			t_prompt *prompt, int *fd_pipe);
void	exec_last_child(t_list *list, t_prompt *prompt, int *fd_pipe);

//Utils
t_prompt	*init_prompt(t_list *processes, t_list **env, t_list **export_list);
void		free_prompt(t_prompt *test);
void		clean_up_processes_list(t_list *list);
char		**string_list_to_bidimensional_array(t_list *env);

#endif