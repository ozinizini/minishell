/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:02:35 by ozini             #+#    #+#             */
/*   Updated: 2024/05/08 18:10:10 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	ft_echo(char *echo_first_argument, char **command,
	int number_of_arguments)
{
	int	i;

	i = 1;
	while (command[i] != NULL)
	{
		if (!(ft_strncmp("-n", (const char *)echo_first_argument,
					ft_strlen((const char *)
						echo_first_argument)) == 0 && i == 1))
		{
			printf("%s", command[i]);
			if (i < number_of_arguments)
				printf(" ");
		}
		i++;
	}
	if ((echo_first_argument && (ft_strncmp("-n",
					(const char *)echo_first_argument, ft_strlen((const char *)
						echo_first_argument)))) || !echo_first_argument)
		printf("\n");
	return (0);
}
