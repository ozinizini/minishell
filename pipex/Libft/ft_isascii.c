/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:21:59 by ozini             #+#    #+#             */
/*   Updated: 2023/12/01 13:31:33 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int main() {
    char ch1 = 'A';   // ASCII value: 65
    char ch2 = '\n';  // ASCII value: 10
    char ch3 = 120;   // Not within ASCII range

    if (ft_isascii(ch1)) {
        printf("%c is within the ASCII character set.\n", ch1);
    } else {
        printf("%c is not within the ASCII character set.\n", ch1);
    }

    if (ft_isascii(ch2)) {
        printf("%c is within the ASCII character set.\n", ch2);
    } else {
        printf("%c is not within the ASCII character set.\n", ch2);
    }

    if (ft_isascii(ch3)) {
        printf("%c is within the ASCII character set.\n", ch3);
    } else {
        printf("%c is not within the ASCII character set.\n", ch3);
    }

    return 0;
}
 */