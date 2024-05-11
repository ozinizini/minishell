/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_error_messages.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:56:05 by ozini             #+#    #+#             */
/*   Updated: 2024/05/08 18:09:31 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	error_message_return(char *error_message, int error_number)
{
	ft_putstr_fd(error_message, 2);
	return (error_number);
}

int	minishell_error_message_return(char *error_description,
	char *source, int error_number)
{
	write(2, "Minishell: ", 11);
	write(2, source, ft_strlen(source));
	write(2, ": ", 2);
	write(2, error_description, ft_strlen(error_description));
	write(2, "\n", 1);
	return (error_number);
}
