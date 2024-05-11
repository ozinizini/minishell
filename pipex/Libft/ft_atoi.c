/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:30:39 by ozini             #+#    #+#             */
/*   Updated: 2024/04/13 15:29:01 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	number(const char *str)
{
	int	atoi;
	int	i;
	int	quotient;

	atoi = 0;
	i = 0;
	quotient = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i > 0)
			quotient *= 10;
		i++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoi += (*str - 48) * quotient;
		str++;
		quotient /= 10;
	}
	return (atoi);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (*str == '0')
		str++;
	if (sign)
		return ((-1) * number(str));
	return (number(str));
}

/* int	main(void)
{
	printf("El número es: %d", ft_atoi( "-2147483649"));
	printf("El número es: %d", atoi( "-2147483649"));
} */
