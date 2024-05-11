#include "./Libft/libft.h"
#include <stdbool.h>
#include <fcntl.h>
#include "pipex_bonus.h"
#include "string.h"
#include "utils_memory_management.h"
#include "utils_error_messages.h"
#include "./built_in/built_in.h"

/* typedef struct s_list
{
    t_process *content;
    t_list *next;
}   t_list; */

void ft_leaks()
{
    system("leaks -q minishell");
}

t_list *initialize_list_env_exit()
{
    t_list *lst = NULL;
    t_list *node = NULL;

/*  t_process *first_process = NULL;
    char **first_process_command = NULL;
    t_list *first_process_redirections = NULL;
    t_redir *first_process_first_redirection = NULL;
    t_redir *first_process_second_redirection  = NULL;
    t_redir *first_process_third_redirection = NULL; */

    t_process *second_process = NULL;
    char **second_process_command = NULL;
    t_list *second_process_redirections = NULL;
/*  t_redir *second_process_second_redirection = NULL;
    t_redir *second_process_third_redirection = NULL;
    t_redir *second_process_first_redirection = NULL; */

/*  t_process *third_process = NULL;
    char **third_process_command;
    t_list *third_process_redirections = NULL;
    t_redir *third_process_first_redirection = NULL;
    t_redir *third_process_second_redirection = NULL;
    t_redir *third_process_third_redirection = NULL; */

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
/*  first_process = malloc(sizeof(t_process));

    first_process_first_redirection = malloc(sizeof(t_redir));
    first_process_second_redirection = malloc(sizeof(t_redir));
    first_process_third_redirection = malloc(sizeof(t_redir));

    first_process_first_redirection->name = ft_strdup("hola");
    first_process_first_redirection->value = HEREDOC;
    first_process_second_redirection->name = ft_strdup("infile");
    first_process_second_redirection->value = INFILE;
    first_process_third_redirection->name = ft_strdup("outfile");
    first_process_third_redirection->value = TRUNCATE; 

    node = ft_lstnew((void *) first_process_first_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_second_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_third_redirection);
    ft_lstadd_back(&first_process_redirections, node);
 
    first_process->redirections = first_process_redirections;
    first_process_command = malloc(sizeof(char *) * 2);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 4);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0], "env");  // Copy "cat" into the allocated memory
    first_process_command[1] = NULL;  // Set the second pointer to NULL
    first_process->command = first_process_command;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;*/

    //SECOND PROCESS
    second_process = malloc(sizeof(t_process));

/*     second_process_first_redirection = malloc(sizeof(t_redir));
    second_process_second_redirection = malloc(sizeof(t_redir));
    second_process_third_redirection = malloc(sizeof(t_redir));

    second_process_first_redirection->name = ft_strdup("infile3");
    second_process_first_redirection->value = INFILE;
    second_process_second_redirection->name = ft_strdup("hola");
    second_process_second_redirection->value = HEREDOC;
    second_process_third_redirection->name = ft_strdup("outfile");
    second_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) second_process_first_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_second_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_third_redirection);
    ft_lstadd_back(&second_process_redirections, node); */

    second_process->redirections = second_process_redirections;

    second_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (second_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    second_process_command[0] = malloc(sizeof(char) * 5);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(second_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[0], "exit");  // Copy "cat" into the allocated memory
    second_process_command[1] = malloc(sizeof(char) * 5);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(second_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[1], "99999999999999999");  // Copy "cat" into the allocated memory
/*  second_process_command[2] = malloc(sizeof(char) * 5);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[2] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(second_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[2], "hola");*/  // Copy "cat" into the allocated memory
    second_process_command[2] = NULL;  // Set the second pointer to NULL
    second_process->command = second_process_command;
    second_process->fd_infile = 0;
    second_process->fd_outfile = 0;
    second_process->heredoc = NULL;
    //THIRD PROCESS
/*     third_process = malloc(sizeof(t_process));

    third_process_first_redirection = malloc(sizeof(t_redir));
    third_process_second_redirection = malloc(sizeof(t_redir));
    third_process_third_redirection = malloc(sizeof(t_redir));

    third_process_first_redirection->name = ft_strdup("aqui");
    third_process_first_redirection->value = HEREDOC;
    third_process_second_redirection->name = ft_strdup("nuevo_file");
    third_process_second_redirection->value = TRUNCATE;
    third_process_third_redirection->name = ft_strdup("nuevo_file_2");
    third_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) third_process_first_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_second_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_third_redirection);
    ft_lstadd_back(&third_process_redirections, node);

    third_process->redirections = third_process_redirections;
    
    third_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (third_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    third_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(third_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[0], "wc");  // Copy "cat" into the allocated memory
    third_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(third_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[1], "-l"); // Copy "cat" into the allocated memory
    third_process_command[2] = NULL;  // Set the second pointer to NULL
    third_process->command = third_process_command;
    third_process->fd_infile = 0;
    third_process->fd_outfile = 0;
    third_process->heredoc = NULL; */

    //CREATING THE LIST

/*  node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);*/
    node = ft_lstnew(second_process);
    ft_lstadd_back(&lst, node);
/*     node = ft_lstnew(third_process);
    ft_lstadd_back(&lst, node); */
    return(lst);
}

t_list *initialize_list_env_wc_l()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    char **first_process_command = NULL;
    t_list *first_process_redirections = NULL;
/*  t_redir *first_process_first_redirection = NULL;
    t_redir *first_process_second_redirection  = NULL;
    t_redir *first_process_third_redirection = NULL; */

    t_process *second_process = NULL;
    char **second_process_command = NULL;
    t_list *second_process_redirections = NULL;
/*  t_redir *second_process_second_redirection = NULL;
    t_redir *second_process_third_redirection = NULL;
    t_redir *second_process_first_redirection = NULL; */

/*  t_process *third_process = NULL;
    char **third_process_command;
    t_list *third_process_redirections = NULL;
    t_redir *third_process_first_redirection = NULL;
    t_redir *third_process_second_redirection = NULL;
    t_redir *third_process_third_redirection = NULL; */

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));

/*     first_process_first_redirection = malloc(sizeof(t_redir));
    first_process_second_redirection = malloc(sizeof(t_redir));
    first_process_third_redirection = malloc(sizeof(t_redir));

    first_process_first_redirection->name = ft_strdup("hola");
    first_process_first_redirection->value = HEREDOC;
    first_process_second_redirection->name = ft_strdup("infile");
    first_process_second_redirection->value = INFILE;
    first_process_third_redirection->name = ft_strdup("outfile");
    first_process_third_redirection->value = TRUNCATE; 

    node = ft_lstnew((void *) first_process_first_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_second_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_third_redirection);
    ft_lstadd_back(&first_process_redirections, node);*/
 
    first_process->redirections = first_process_redirections;
    first_process_command = malloc(sizeof(char *) * 2);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 4);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0], "env");  // Copy "cat" into the allocated memory
    first_process_command[1] = NULL;  // Set the second pointer to NULL
    first_process->command = first_process_command;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //SECOND PROCESS
    second_process = malloc(sizeof(t_process));

/*     second_process_first_redirection = malloc(sizeof(t_redir));
    second_process_second_redirection = malloc(sizeof(t_redir));
    second_process_third_redirection = malloc(sizeof(t_redir));

    second_process_first_redirection->name = ft_strdup("infile3");
    second_process_first_redirection->value = INFILE;
    second_process_second_redirection->name = ft_strdup("hola");
    second_process_second_redirection->value = HEREDOC;
    second_process_third_redirection->name = ft_strdup("outfile");
    second_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) second_process_first_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_second_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_third_redirection);
    ft_lstadd_back(&second_process_redirections, node); */

    second_process->redirections = second_process_redirections;

    second_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (second_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    second_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(second_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[0], "wc");  // Copy "cat" into the allocated memory
    second_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(second_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[1], "-l");  // Copy "cat" into the allocated memory
    second_process_command[2] = NULL;  // Set the second pointer to NULL
    second_process->command = second_process_command;
    second_process->fd_infile = 0;
    second_process->fd_outfile = 0;
    second_process->heredoc = NULL;
    //THIRD PROCESS
/*     third_process = malloc(sizeof(t_process));

    third_process_first_redirection = malloc(sizeof(t_redir));
    third_process_second_redirection = malloc(sizeof(t_redir));
    third_process_third_redirection = malloc(sizeof(t_redir));

    third_process_first_redirection->name = ft_strdup("aqui");
    third_process_first_redirection->value = HEREDOC;
    third_process_second_redirection->name = ft_strdup("nuevo_file");
    third_process_second_redirection->value = TRUNCATE;
    third_process_third_redirection->name = ft_strdup("nuevo_file_2");
    third_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) third_process_first_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_second_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_third_redirection);
    ft_lstadd_back(&third_process_redirections, node);

    third_process->redirections = third_process_redirections;
    
    third_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (third_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    third_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(third_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[0], "wc");  // Copy "cat" into the allocated memory
    third_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(third_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[1], "-l"); // Copy "cat" into the allocated memory
    third_process_command[2] = NULL;  // Set the second pointer to NULL
    third_process->command = third_process_command;
    third_process->fd_infile = 0;
    third_process->fd_outfile = 0;
    third_process->heredoc = NULL; */

    //CREATING THE LIST

    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);
    node = ft_lstnew(second_process);
    ft_lstadd_back(&lst, node);
/*     node = ft_lstnew(third_process);
    ft_lstadd_back(&lst, node); */
    return(lst);
}



















t_list *initialize_list_export_child()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    char **first_process_command = NULL;
    t_list *first_process_redirections = NULL;
/*  t_redir *first_process_first_redirection = NULL;
    t_redir *first_process_second_redirection  = NULL;
    t_redir *first_process_third_redirection = NULL; */

    t_process *second_process = NULL;
    char **second_process_command = NULL;
    t_list *second_process_redirections = NULL;
/*  t_redir *second_process_second_redirection = NULL;
    t_redir *second_process_third_redirection = NULL;
    t_redir *second_process_first_redirection = NULL; */

/*  t_process *third_process = NULL;
    char **third_process_command;
    t_list *third_process_redirections = NULL;
    t_redir *third_process_first_redirection = NULL;
    t_redir *third_process_second_redirection = NULL;
    t_redir *third_process_third_redirection = NULL; */

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));

/*     first_process_first_redirection = malloc(sizeof(t_redir));
    first_process_second_redirection = malloc(sizeof(t_redir));
    first_process_third_redirection = malloc(sizeof(t_redir));

    first_process_first_redirection->name = ft_strdup("hola");
    first_process_first_redirection->value = HEREDOC;
    first_process_second_redirection->name = ft_strdup("infile");
    first_process_second_redirection->value = INFILE;
    first_process_third_redirection->name = ft_strdup("outfile");
    first_process_third_redirection->value = TRUNCATE; 

    node = ft_lstnew((void *) first_process_first_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_second_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_third_redirection);
    ft_lstadd_back(&first_process_redirections, node);*/
 
    first_process->redirections = first_process_redirections;
    first_process_command = malloc(sizeof(char *) * 5);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 7);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0], "export");  // Copy "cat" into the allocated memory

    first_process_command[1] = malloc(sizeof(char) * 12);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[1], "saludo=hola");  // Copy "cat" into the allocated memory

    first_process_command[2] = malloc(sizeof(char) * 12);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[2] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[2], "nombre=omar");  // Copy "cat" into the allocated memory


    first_process_command[3] = malloc(sizeof(char) * 6);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[3] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[3], "amigo");  // Copy "cat" into the allocated memory

    first_process_command[4] = NULL;  // Set the second pointer to NULL
    first_process->command = first_process_command;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //SECOND PROCESS
    second_process = malloc(sizeof(t_process));

/*     second_process_first_redirection = malloc(sizeof(t_redir));
    second_process_second_redirection = malloc(sizeof(t_redir));
    second_process_third_redirection = malloc(sizeof(t_redir));

    second_process_first_redirection->name = ft_strdup("infile3");
    second_process_first_redirection->value = INFILE;
    second_process_second_redirection->name = ft_strdup("hola");
    second_process_second_redirection->value = HEREDOC;
    second_process_third_redirection->name = ft_strdup("outfile");
    second_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) second_process_first_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_second_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_third_redirection);
    ft_lstadd_back(&second_process_redirections, node); */

    second_process->redirections = second_process_redirections;

    second_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (second_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    second_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(second_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[0], "wc");  // Copy "cat" into the allocated memory
    second_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(second_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[1], "-l");  // Copy "cat" into the allocated memory
    second_process_command[2] = NULL;  // Set the second pointer to NULL
    second_process->command = second_process_command;
    second_process->fd_infile = 0;
    second_process->fd_outfile = 0;
    second_process->heredoc = NULL;
    //THIRD PROCESS
/*     third_process = malloc(sizeof(t_process));

    third_process_first_redirection = malloc(sizeof(t_redir));
    third_process_second_redirection = malloc(sizeof(t_redir));
    third_process_third_redirection = malloc(sizeof(t_redir));

    third_process_first_redirection->name = ft_strdup("aqui");
    third_process_first_redirection->value = HEREDOC;
    third_process_second_redirection->name = ft_strdup("nuevo_file");
    third_process_second_redirection->value = TRUNCATE;
    third_process_third_redirection->name = ft_strdup("nuevo_file_2");
    third_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) third_process_first_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_second_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_third_redirection);
    ft_lstadd_back(&third_process_redirections, node);

    third_process->redirections = third_process_redirections;
    
    third_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (third_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    third_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(third_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[0], "wc");  // Copy "cat" into the allocated memory
    third_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(third_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[1], "-l"); // Copy "cat" into the allocated memory
    third_process_command[2] = NULL;  // Set the second pointer to NULL
    third_process->command = third_process_command;
    third_process->fd_infile = 0;
    third_process->fd_outfile = 0;
    third_process->heredoc = NULL; */

    //CREATING THE LIST

    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);
    node = ft_lstnew(second_process);
    ft_lstadd_back(&lst, node);
/*     node = ft_lstnew(third_process);
    ft_lstadd_back(&lst, node); */
    return(lst);
}
















t_list *initialize_list_cat_cat_ls()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    char **first_process_command = NULL;
    t_list *first_process_redirections = NULL;

    t_process *second_process = NULL;
    char **second_process_command = NULL;
    t_list *second_process_redirections = NULL;

    t_process *third_process = NULL;
    char **third_process_command;
    t_list *third_process_redirections = NULL;

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));
    first_process->redirections = first_process_redirections;
    first_process_command = malloc(sizeof(char *) * 2);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 4);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0], "cat");  // Copy "cat" into the allocated memory
    first_process_command[1] = NULL;  // Set the second pointer to NULL
    first_process->command = first_process_command;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //SECOND PROCESS
    second_process = malloc(sizeof(t_process));
    second_process->redirections = second_process_redirections;

    second_process_command = malloc(sizeof(char *) * 2);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (second_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    second_process_command[0] = malloc(sizeof(char) * 4);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(second_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[0], "cat");  // Copy "cat" into the allocated memory
    second_process_command[1] = NULL;  // Set the second pointer to NULL
    second_process->command = second_process_command;
    second_process->fd_infile = 0;
    second_process->fd_outfile = 0;
    second_process->heredoc = NULL;
    //THIRD PROCESS
    third_process = malloc(sizeof(t_process));
    third_process->redirections = third_process_redirections;
    
    third_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (third_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    third_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(third_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[0], "ls");  // Copy "cat" into the allocated memory
    third_process_command[1] = malloc(sizeof(char) * 13);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(third_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[1], "/nonexistent"); // Copy "cat" into the allocated memory
    third_process_command[2] = NULL;  // Set the second pointer to NULL
    third_process->command = third_process_command;
    third_process->fd_infile = 0;
    third_process->fd_outfile = 0;
    third_process->heredoc = NULL;

    //CREATING THE LIST

    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);
    node = ft_lstnew(second_process);
    ft_lstadd_back(&lst, node);
    node = ft_lstnew(third_process);
    ft_lstadd_back(&lst, node);
    return(lst);
}

t_list *initialize_list_exit()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    t_list *first_process_redirections = NULL;
    char **first_process_command = NULL;

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));

    first_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 4 pointers (one for "export", one for "saludo=hola", one for "toma", one for "adios", and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 5);  // Allocate memory for 7 characters (6 for "export" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0],"exit");  // Copy "export" into the allocated memory
    first_process_command[1] = malloc(sizeof(char) * 5);  // Allocate memory for 12 characters (11 for "saludo=hola" and 1 for the null terminator)

     if (first_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[1], "h567");  // Copy "saludo=hola" into the allocated memory
    first_process_command[2] = malloc(sizeof(char) * 4);  // Allocate memory for 5 characters (4 for "toma" and 1 for the null terminator)

    if (first_process_command[2] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[2], "4800");  // Copy "toma" into the allocated memory
/*  first_process_command[3] = malloc(sizeof(char) * 6);  // Allocate memory for 6 characters (5 for "adios" and 1 for the null terminator)

    if (first_process_command[3] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[3], "adios");  // Copy "adios" into the allocated memory


    first_process_command[4] = malloc(sizeof(char) * 4);  // Allocate memory for 6 characters (5 for "adios" and 1 for the null terminator)

    if (first_process_command[4] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[4], "PWD");  // Copy "adios" into the allocated memory */
    first_process_command[3] = NULL;  // Set the last pointer to NULL
    first_process->command = first_process_command;
    first_process->redirections = first_process_redirections;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //CREATING THE LIST
    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);

    return(lst);
}

t_list *initialize_list_null()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    t_list *first_process_redirections = NULL;
    char **first_process_command = NULL;

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));
    first_process->command = first_process_command;
    first_process->redirections = first_process_redirections;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //CREATING THE LIST
    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);

    return(lst);
}
t_list *initialize_list_unset()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    t_list *first_process_redirections = NULL;
    char **first_process_command = NULL;

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));

    first_process_command = malloc(sizeof(char *) * 6);  // Allocate memory for 4 pointers (one for "export", one for "saludo=hola", one for "toma", one for "adios", and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 7);  // Allocate memory for 7 characters (6 for "export" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0],"export");  // Copy "export" into the allocated memory
    first_process_command[1] = malloc(sizeof(char) * 7);  // Allocate memory for 12 characters (11 for "saludo=hola" and 1 for the null terminator)

    if (first_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[1], "saludo");  // Copy "saludo=hola" into the allocated memory
    first_process_command[2] = malloc(sizeof(char) * 9);  // Allocate memory for 5 characters (4 for "toma" and 1 for the null terminator)

    if (first_process_command[2] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[2], "HOME=EVA");  // Copy "toma" into the allocated memory
    first_process_command[3] = malloc(sizeof(char) * 6);  // Allocate memory for 6 characters (5 for "adios" and 1 for the null terminator)

    if (first_process_command[3] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[3], "adios");  // Copy "adios" into the allocated memory


    first_process_command[4] = malloc(sizeof(char) * 4);  // Allocate memory for 6 characters (5 for "adios" and 1 for the null terminator)

    if (first_process_command[4] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[4], "PWD");  // Copy "adios" into the allocated memory
    first_process_command[5] = NULL;  // Set the last pointer to NULL
    first_process->command = first_process_command;
    first_process->redirections = first_process_redirections;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //CREATING THE LIST
    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);

    return(lst);
}

/*t_list *initialize_list_export()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    t_list *first_process_redirections = NULL;
    char **first_process_command = NULL;

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));

    first_process_command = malloc(sizeof(char *) * 5);  // Allocate memory for 4 pointers (one for "export", one for "saludo=hola", one for "toma", one for "adios", and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 7);  // Allocate memory for 7 characters (6 for "export" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0], "export");  // Copy "export" into the allocated memory
    first_process_command[1] = malloc(sizeof(char) * 12);  // Allocate memory for 12 characters (11 for "saludo=hola" and 1 for the null terminator)

    if (first_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[1], "saludo=hola");  // Copy "saludo=hola" into the allocated memory
    first_process_command[2] = malloc(sizeof(char) * 5);  // Allocate memory for 5 characters (4 for "toma" and 1 for the null terminator)

    if (first_process_command[2] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[2], "toma");  // Copy "toma" into the allocated memory
    first_process_command[3] = malloc(sizeof(char) * 6);  // Allocate memory for 6 characters (5 for "adios" and 1 for the null terminator)

    if (first_process_command[3] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[3], "adios");  // Copy "adios" into the allocated memory
    first_process_command[4] = NULL;  // Set the last pointer to NULL
    first_process->command = first_process_command;
    first_process->redirections = first_process_redirections;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //CREATING THE LIST
    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);

    return(lst);
}
*/


t_list *initialize_list()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    char **first_process_command = NULL;
    t_list *first_process_redirections = NULL;
/*  t_redir *first_process_first_redirection = NULL;
    t_redir *first_process_second_redirection  = NULL;
    t_redir *first_process_third_redirection = NULL; */

/*     t_process *second_process = NULL;
    char **second_process_command = NULL;
    t_list *second_process_redirections = NULL;
    t_redir *second_process_second_redirection = NULL;
    t_redir *second_process_third_redirection = NULL;
    t_redir *second_process_first_redirection = NULL;

    t_process *third_process = NULL;
    char **third_process_command;
    t_list *third_process_redirections = NULL;
    t_redir *third_process_first_redirection = NULL;
    t_redir *third_process_second_redirection = NULL;
    t_redir *third_process_third_redirection = NULL;
 */
    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));

/*  first_process_first_redirection = malloc(sizeof(t_redir));
    first_process_second_redirection = malloc(sizeof(t_redir));
    first_process_third_redirection = malloc(sizeof(t_redir));

    first_process_first_redirection->name = ft_strdup("hola");
    first_process_first_redirection->value = HEREDOC;
    first_process_second_redirection->name = ft_strdup("infile");
    first_process_second_redirection->value = INFILE;
    first_process_third_redirection->name = ft_strdup("outfile");
    first_process_third_redirection->value = TRUNCATE;

    node = ft_lstnew((void *) first_process_first_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_second_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_third_redirection);
    ft_lstadd_back(&first_process_redirections, node);*/
 
    first_process->redirections = first_process_redirections;
    first_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0], "cd");  // Copy "cat" into the allocated memory
    
    first_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(first_process_command[1], "..");  // Copy "cat" into the allocated memory */
    first_process_command[2] = NULL;  // Set the second pointer to NULL
    first_process->command = first_process_command;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //SECOND PROCESS
 /*    second_process = malloc(sizeof(t_process));

    second_process_first_redirection = malloc(sizeof(t_redir));
    second_process_second_redirection = malloc(sizeof(t_redir));
    second_process_third_redirection = malloc(sizeof(t_redir));

    second_process_first_redirection->name = ft_strdup("infile3");
    second_process_first_redirection->value = INFILE;
    second_process_second_redirection->name = ft_strdup("hola");
    second_process_second_redirection->value = HEREDOC;
    second_process_third_redirection->name = ft_strdup("outfile");
    second_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) second_process_first_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_second_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_third_redirection);
    ft_lstadd_back(&second_process_redirections, node);

    second_process->redirections = second_process_redirections;

    second_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (second_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    second_process_command[0] = malloc(sizeof(char) * 14);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(second_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[0], "/usr/bin/grep");  // Copy "cat" into the allocated memory
    second_process_command[1] = malloc(sizeof(char) * 2);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(second_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[1], "a");  // Copy "cat" into the allocated memory
    second_process_command[2] = NULL;  // Set the second pointer to NULL
    second_process->command = second_process_command;
    second_process->fd_infile = 0;
    second_process->fd_outfile = 0;
    second_process->heredoc = NULL; */
    //THIRD PROCESS
/*     third_process = malloc(sizeof(t_process));

    third_process_first_redirection = malloc(sizeof(t_redir));
    third_process_second_redirection = malloc(sizeof(t_redir));
    third_process_third_redirection = malloc(sizeof(t_redir));

    third_process_first_redirection->name = ft_strdup("aqui");
    third_process_first_redirection->value = HEREDOC;
    third_process_second_redirection->name = ft_strdup("nuevo_file");
    third_process_second_redirection->value = TRUNCATE;
    third_process_third_redirection->name = ft_strdup("nuevo_file_2");
    third_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) third_process_first_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_second_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_third_redirection);
    ft_lstadd_back(&third_process_redirections, node);

    third_process->redirections = third_process_redirections;
    
    third_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (third_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    third_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(third_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[0], "wc");  // Copy "cat" into the allocated memory
    third_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(third_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[1], "-l"); // Copy "cat" into the allocated memory
    third_process_command[2] = NULL;  // Set the second pointer to NULL
    third_process->command = third_process_command;
    third_process->fd_infile = 0;
    third_process->fd_outfile = 0;
    third_process->heredoc = NULL;
 */
    //CREATING THE LIST

    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);
/*     node = ft_lstnew(second_process);
    ft_lstadd_back(&lst, node);
    node = ft_lstnew(third_process);
    ft_lstadd_back(&lst, node); */
    return(lst); 
}



t_list *initialize_list_with_infiles()
{
    t_list *lst = NULL;
    t_list *node = NULL;

    t_process *first_process = NULL;
    char **first_process_command = NULL;
    t_list *first_process_redirections = NULL;
    t_redir *first_process_first_redirection = NULL;
    t_redir *first_process_second_redirection  = NULL;
    t_redir *first_process_third_redirection = NULL;

    t_process *second_process = NULL;
    char **second_process_command = NULL;
    t_list *second_process_redirections = NULL;
    t_redir *second_process_second_redirection = NULL;
    t_redir *second_process_third_redirection = NULL;
    t_redir *second_process_first_redirection = NULL;

    t_process *third_process = NULL;
    char **third_process_command;
    t_list *third_process_redirections = NULL;
    t_redir *third_process_first_redirection = NULL;
    t_redir *third_process_second_redirection = NULL;
    t_redir *third_process_third_redirection = NULL;

    lst = NULL;
    node = NULL;

    //FIRST PROCESS
    first_process = malloc(sizeof(t_process));

    first_process_first_redirection = malloc(sizeof(t_redir));
    first_process_second_redirection = malloc(sizeof(t_redir));
    first_process_third_redirection = malloc(sizeof(t_redir));

    first_process_first_redirection->name = ft_strdup("hola");
    first_process_first_redirection->value = HEREDOC;
    first_process_second_redirection->name = ft_strdup("infile");
    first_process_second_redirection->value = INFILE;
    first_process_third_redirection->name = ft_strdup("outfile");
    first_process_third_redirection->value = TRUNCATE;

    node = ft_lstnew((void *) first_process_first_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_second_redirection);
    ft_lstadd_back(&first_process_redirections, node);
    node = ft_lstnew((void *) first_process_third_redirection);
    ft_lstadd_back(&first_process_redirections, node);
 
    first_process->redirections = first_process_redirections;
    first_process_command = malloc(sizeof(char *) * 2);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)

    if (first_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    first_process_command[0] = malloc(sizeof(char) * 4);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)

    if (first_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(first_process_command);
        exit(EXIT_FAILURE);
    }

    strcpy(first_process_command[0], "cat");  // Copy "cat" into the allocated memory
    first_process_command[1] = NULL;  // Set the second pointer to NULL
    first_process->command = first_process_command;
    first_process->fd_infile = 0;
    first_process->fd_outfile = 0;
    first_process->heredoc = NULL;

    //SECOND PROCESS
    second_process = malloc(sizeof(t_process));

    second_process_first_redirection = malloc(sizeof(t_redir));
    second_process_second_redirection = malloc(sizeof(t_redir));
    second_process_third_redirection = malloc(sizeof(t_redir));

    second_process_first_redirection->name = ft_strdup("infile3");
    second_process_first_redirection->value = INFILE;
    second_process_second_redirection->name = ft_strdup("hola");
    second_process_second_redirection->value = HEREDOC;
    second_process_third_redirection->name = ft_strdup("outfile");
    second_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) second_process_first_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_second_redirection);
    ft_lstadd_back(&second_process_redirections, node);
    node = ft_lstnew((void *) second_process_third_redirection);
    ft_lstadd_back(&second_process_redirections, node);

    second_process->redirections = second_process_redirections;

    second_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (second_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    second_process_command[0] = malloc(sizeof(char) * 14);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(second_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[0], "/usr/bin/grep");  // Copy "cat" into the allocated memory
    second_process_command[1] = malloc(sizeof(char) * 2);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (second_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(second_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(second_process_command[1], "a");  // Copy "cat" into the allocated memory
    second_process_command[2] = NULL;  // Set the second pointer to NULL
    second_process->command = second_process_command;
    second_process->fd_infile = 0;
    second_process->fd_outfile = 0;
    second_process->heredoc = NULL;
    //THIRD PROCESS
    third_process = malloc(sizeof(t_process));

    third_process_first_redirection = malloc(sizeof(t_redir));
    third_process_second_redirection = malloc(sizeof(t_redir));
    third_process_third_redirection = malloc(sizeof(t_redir));

    third_process_first_redirection->name = ft_strdup("aqui");
    third_process_first_redirection->value = HEREDOC;
    third_process_second_redirection->name = ft_strdup("nuevo_file");
    third_process_second_redirection->value = TRUNCATE;
    third_process_third_redirection->name = ft_strdup("nuevo_file_2");
    third_process_third_redirection->value = APPEND;

    node = ft_lstnew((void *) third_process_first_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_second_redirection);
    ft_lstadd_back(&third_process_redirections, node);
    node = ft_lstnew((void *) third_process_third_redirection);
    ft_lstadd_back(&third_process_redirections, node);

    third_process->redirections = third_process_redirections;
    
    third_process_command = malloc(sizeof(char *) * 3);  // Allocate memory for 2 pointers (one for "cat" and one for NULL)
    if (third_process_command == NULL) {
        // handle error, e.g., print an error message and exit
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    third_process_command[0] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[0] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        free(third_process_command);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[0], "wc");  // Copy "cat" into the allocated memory
    third_process_command[1] = malloc(sizeof(char) * 3);  // Allocate memory for 4 characters (3 for "cat" and 1 for the null terminator)
    if (third_process_command[1] == NULL) {
        // handle error
        fprintf(stderr, "Memory allocation failed\n");
        //free(third_process_first_redirection);
        exit(EXIT_FAILURE);
    }
    strcpy(third_process_command[1], "-l"); // Copy "cat" into the allocated memory
    third_process_command[2] = NULL;  // Set the second pointer to NULL
    third_process->command = third_process_command;
    third_process->fd_infile = 0;
    third_process->fd_outfile = 0;
    third_process->heredoc = NULL;

    //CREATING THE LIST

    node = ft_lstnew((void *)first_process);
    ft_lstadd_back(&lst,node);
    node = ft_lstnew(second_process);
    ft_lstadd_back(&lst, node);
    node = ft_lstnew(third_process);
    ft_lstadd_back(&lst, node);
    return(lst);
}
int main(int argc, char **argv, char **env)
{
    t_list *lst_of_processes;
    t_list *lst_env;
    t_list	*export_list;
    t_list *temp;
    int     exit_status;

    (void)argc;
    (void)argv;
    //(void)env;
    lst_env = NULL;
    temp = NULL;
    //atexit(ft_leaks);
    lst_of_processes = initialize_list_env_exit();
    lst_env = create_env_list(env);
    export_list = create_env_list(env);
/*  printf("The size of the list is %d\n", ft_lstsize(lst_env));
    temp = lst_env;
    while(temp != NULL)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }*/
    exit_status = pipex(lst_of_processes, &lst_env, &export_list);
    clean_up_processes_list(lst_of_processes);
    sort_list(lst_env);
/*     while(lst_env != NULL)
    {
        printf("%s\n", (char *)lst_env->content);
        //free(lst_env);
        lst_env = lst_env->next;
    } */
    /* printf("\n\n\n");
    sort_list(export_list);
    while(export_list != NULL)
    {
        printf("%s\n", (char *)export_list->content);
        //free(lst_env);
        export_list = export_list->next;
    } */
/*     printf("\n\n\nThe size of the list is %d\n", ft_lstsize(lst_env));
    while(lst_env != NULL)
    {
        printf("%s\n", (char *)lst_env->content);
        lst_env = lst_env->next;
    } */
    printf("Exit status = %d", exit_status);
}


/* int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    t_list *list;
//    t_list *redirections;
//    int process_count;

    atexit(ft_leaks);
    list = NULL;
    list = initialize_list();
    redirections = NULL;
    process_count = 0;
    while(list != NULL)
    {
        printf("%s\n", ((t_process *)list->content)->command[0]);
        redirections = ((t_process *)list->content)->redirections;
        while(redirections != NULL)
        {
            printf("File name: %s, redirection reference: %d\n", ((t_redir *)redirections->content)->name, ((t_redir *)redirections->content)->value);
            printf("----------------------\n");
            redirections = redirections->next;
        }
        list = list->next;
        process_count++;
    }
    //Tengo que pasarle a mi Pipex Bonus tres variables
    //recordar que mi Pipex Bonus tiene un main cuyos argumentos son
    //int argc --> Es el tamaño de mi lista + 1. Tengo que sacar el tamaño de mi lista con un ft_list_size
    //char **argv --> En mi pipex la estructura era esta: infile "grep a" pipe "cat" pipe "wc -l" outfile, donde:
    //     infile "grep a" pertenecían al infile_child_process_bonus
    //     "cat" pertenecían al intermediate_children_process
    //     "wc -l" outfile pertenecen al outfile_child_process_bonus
    //      tendré que recorrer la t_list formada de nodos de tipo t_process y acceder al campo command_arguments.

    //char **env -> es la lista que he creado para env, es decir, ahora es un t_list.

    //La primera prueba que tengo que hacer es modelar una lista de t_process que tengan una estructura igual a mi pipex: infile command1 command2 ... commandn outfile.
    
    //pipex(int list_size, t_list *list, char **env)
    //pipex(process_count + 1, list, env)
    
    //printf("There are %d nodes\n", process_count);

    clean_up_list(list);
} */