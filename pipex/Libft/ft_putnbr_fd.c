/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:53:16 by ozini             #+#    #+#             */
/*   Updated: 2023/12/09 11:55:14 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static long	number_sign_and_type(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	return (nb);
}

static void	extreme_cases(long n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write (fd, &n, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		divisor;
	int		cociente;
	int		resto;
	long	nb;

	divisor = 10;
	cociente = 0;
	resto = 0;
	nb = number_sign_and_type(n, fd);
	if (nb >= 0 && nb <= 9)
		extreme_cases(nb, fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}

/* int main(void)
{
	ft_putnbr_fd(-57,1);
}
 */