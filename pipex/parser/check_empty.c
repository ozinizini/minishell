/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:32:23 by arosas-j          #+#    #+#             */
/*   Updated: 2024/05/14 19:34:29 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_empty(char *s)
{
	size_t	i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			return (0);
		else
			return (1);
	}
	return (1);
}
