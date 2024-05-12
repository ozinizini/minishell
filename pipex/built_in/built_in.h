/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:44:05 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 16:47:13 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "../Libft/libft.h"
# include "string.h"
# include <errno.h>

//Error messages management
int		error_message_return(char *error_message, int error_number);
int		minishell_error_message_return(char *error_description, char *source,
			int error_number);
//Built-in utils
int		env_variable_exists(t_list *env, char *export_variable);
void	ft_delete_node(t_list **list, int node_position);
void	sort_list(t_list *list);

//String functions to handle environment variable names
int		forbidden_variable_name(char *export_variable);
int		string_contains_equal_sign(char *export_variable);
char	*variable_name(char *export_variable);
//Adding and replacing variables
int		add_new_env_variable(t_list **env, char *export_variable);
int		replace_existing_env_variable(t_list **env, char *export_variable,
			int env_variable_position);
//Changing directory
int		ft_cd(char *path, t_list **env, t_list **export_list);

//Echoing input
int		ft_echo(char **command, int number_of_arguments);
//Printing environment variables
int		ft_env(t_list *env);
//Exit
void	ft_exit(char *error_argument, int *exit_status,
			int number_of_arguments, int is_only_process);
//pwd
int		ft_pwd(void);
// export environment variables and export list creation
int		ft_export(t_list **env, t_list **export_list, char *export_variable);
int		handle_variables_export(t_list **env, t_list **export_list,
			char **export_variables, int number_of_variables);
// unsetting variables
int		handle_variables_unset(t_list **env, t_list **export_list,
			char **export_variables, int number_of_variables);

#endif