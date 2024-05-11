/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:08:46 by ozini             #+#    #+#             */
/*   Updated: 2024/05/08 18:10:30 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	ft_pwd(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	return (0);
}
