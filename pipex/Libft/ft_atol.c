/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:28:03 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 12:58:24 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

static long	number(const char *str)
{
	long    atoi;
	int     i;
	long    quotient;

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

long    ft_atol(const char *str)
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
	printf("El número con ft_es: %ld\n", ft_atol( "9223372036854775807"));
	printf("El número es: %ld\n", atol( "9223372036854775808"));
	if (errno == ERANGE)	
		printf("errno: %d\n", errno);
} */