/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:02:35 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 16:46:53 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	ft_echo(char **command, int number_of_arguments)
{
	int	i;
	int	n_option_flag;

	i = 1;
	n_option_flag = 0;
	while (command[i] != NULL)
	{
		if (i == 1)
		{
			while ((!ft_strcmp("-n", (const char *)command[i])) && command[i])
			{
				n_option_flag = 1;
				i++;
			}
			if (!command)
				break ;
		}
		printf("%s", command[i]);
		if (i < number_of_arguments)
			printf(" ");
		i++;
	}
	if (!(n_option_flag) || !command[1])
		printf("\n");
	return (0);
}
