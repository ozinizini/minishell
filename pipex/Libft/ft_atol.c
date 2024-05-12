/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:28:03 by ozini             #+#    #+#             */
/*   Updated: 2024/05/12 14:36:55 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

static long	check_quotient(long quotient)
{
	if (LONG_MAX >= quotient * 10)
		return (quotient * 10);
	else
	{
		errno = ERANGE;
		return (quotient);
	}
}

static long	check_number(int digit, long atol, long quotient)
{
	if (digit <= (LONG_MAX - atol) / quotient)
	{
		atol += digit * quotient;
		return (atol);
	}
	else
	{
		errno = ERANGE;
		return (atol);
	}
}

static long	number(const char *str)
{
	long	atol;
	int		i;
	long	quotient;

	atol = 0;
	i = 0;
	quotient = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i++ > 0)
		{
			quotient = check_quotient(quotient);
			if (errno == ERANGE)
				return (quotient);
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		atol = check_number(*str - 48, atol, quotient);
		str++;
		quotient /= 10;
	}
	return (atol);
}

long	ft_atol(const char *str)
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
	int		saved_errno;
	long	number;

	//number = ft_atol( "922337203685477580899808098098098");
	number = ft_atol("9223372036854775808");
	saved_errno = errno;
	if (saved_errno == ERANGE)
		printf("errno: %d\n", saved_errno);
	else
		printf("El número con ft_es: %ld\n", number);
	//printf("El número es: %ld\n", atol( "9223372036854775807"));
} */
