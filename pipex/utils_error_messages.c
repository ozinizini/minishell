/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_messages.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:36:14 by ozini             #+#    #+#             */
/*   Updated: 2024/04/25 11:16:18 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_error_messages.h"

void	bash_error_message(char *error_description, char *source)
{
	ft_putstr_fd("Entra en bash_error_message \n", 2);
	write(2, "bash: ", 6);
	write(2, source, ft_strlen(source));
	write(2, ": ", 2);
	write(2, error_description, ft_strlen(error_description));
	write(2, "\n", 1);
}

void	error_message(char *error_message)
{
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
