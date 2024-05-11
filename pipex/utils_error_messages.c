/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error_messages.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:36:14 by ozini             #+#    #+#             */
/*   Updated: 2024/05/11 18:31:32 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_error_messages.h"

void	bash_error_message(char *error_description, char *source)
{
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
