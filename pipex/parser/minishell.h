/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:57:23 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/17 18:31:22 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include "../Libft/libft.h"

typedef enum e_File_Type
{
	INFILE = 0,
	HEREDOC = 1,
	TRUNCATE = 2,
	APPEND = 3,
	INVALID_REDIR = 4,
}	t_File_Type;

typedef struct s_redir
{
	char			*name;
	t_File_Type		value;
}					t_redir;

typedef struct s_process
{
	t_list		*redirections;
	char		**command;
	int			fd_infile;
	int			fd_outfile;
	char		*heredoc;
}				t_process;

typedef struct s_var
{
	t_list	*env_list;
	int		exit_status;
}			t_var;

//Check syntax

int				ft_check_syntax(char *line);

//Parser

t_list			*parser(char *line, t_list *env, int var);
void			get_process_list(char **str_process, t_list **list);
void			parse_list(t_list *process_list, t_list *env);
t_process		*parse_process(void *str_process, t_list *env);
void			init_process_struct(t_process *process);

//Quotes

size_t			skip_all_quotes(char *str, size_t i);
size_t			skip_single_quotes(char *str, size_t i);
size_t			skip_double_quotes(char *str, size_t i);
char			*ft_clean_quotes(char *line);

//Splits

char			**ft_split_process(char *s);
char			**ft_split_words(char *s);
int				check_empty(char *s);

//Redirections

void			get_redir(char *str_process, t_process *process, t_list *env);
void			add_redir_list(char *ptr, t_process *process, t_list *env);
char			*clear_str(char *str_process, size_t i);
char			*get_file_str(char *redir_str);
t_redir			*split_redir(char *ptr);
t_File_Type		get_redir_type(char *ptr);
t_File_Type		get_infile(char *ptr);
t_File_Type		get_outfile(char *ptr);

//Expander

char			*expander(char *line, t_list *env);
char			*expand_line(char *line, size_t len, t_list *env);
void			manage_variable(char *str, char *exp, t_list *env, size_t *i);
void			manage_quotes(char *line, char *expanded_line, size_t *i);
void			copy_char(char *line, char *expanded_line, size_t *i);
size_t			get_expanded_len(char *line, t_list *env);
size_t			get_variable_size(char *variable, t_list *env);
char			*get_variable_value(char *variable_name, t_list *env);
char			*get_variable_name(char *str);
int				compare_name(char *variable_name, char *env);
size_t			skip_variable(char *line, size_t i);

//Signals
void			quit_handler(int sig);
void			int_handler(int sig);
void			int_exe_sig(int sig);
void			int_heredoc(int sig);
void			set_echoctl(int fd, int enable);

extern	int	g_sig;

#endif
