/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:02:45 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 10:21:02 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*transform_to_char(int n, int quotient, int int_len, int sign)
{
	char	*itoa;
	int		i;

	i = 0;
	itoa = (char *)malloc(int_len * sizeof(char));
	if (itoa == NULL)
		return (NULL);
	if (sign)
		itoa[i++] = '-';
	while (quotient >= 10)
	{
		itoa[i++] = (n / quotient) + 48;
		n = n % quotient;
		quotient /= 10;
	}
	itoa[i] = (n / quotient) + 48;
	itoa[i + 1] = '\0';
	return (itoa);
}

char	*ft_itoa(int n)
{
	int				i;
	int				int_len;
	int				quotient;
	int				sign;

	quotient = 1;
	i = 0;
	int_len = 2;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		int_len++;
		n = -n;
		sign = 1;
	}
	while (n / quotient >= 10)
	{
		quotient *= 10;
		int_len ++;
	}
	return (transform_to_char(n, quotient, int_len, sign));
}

/* int	main(void)
{
	int	numero;
	numero = 0;
	printf("El número %d en formato texto es %s", numero, ft_itoa((numero)));
}   */