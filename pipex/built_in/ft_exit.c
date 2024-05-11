/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:21:08 by ozini             #+#    #+#             */
/*   Updated: 2024/05/10 16:09:09 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	exit_numeric_argument_required_error(char *error_argument)
{
	int	i;

	i = 0;
	while (error_argument[i] != '\0')
		if (!(ft_isdigit(error_argument[i++])))
			break ;
	if (error_argument[i])
	{
		ft_putstr_fd("Minishell: exit: ", 2);
		ft_putstr_fd(error_argument, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
}

void	ft_exit(char *error_argument, int *exit_status, int number_of_arguments, int is_only_process)
{
	if (is_only_process == 1)
		printf("exit\n");
	if (number_of_arguments > 1)
	{
		exit_numeric_argument_required_error(error_argument);
		printf("Minishell: exit: too many arguments\n");
		*exit_status = 1;
		return ;
	}
	if (error_argument == NULL)
		exit(*exit_status);
	else
	{
		exit_numeric_argument_required_error(error_argument);
		exit(ft_atoi((const char *)error_argument) % 256);
	}
}
