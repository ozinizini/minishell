/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:16:55 by ozini             #+#    #+#             */
/*   Updated: 2023/11/30 11:18:24 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* int main() {
    char ch1 = 'A';  // Alphabetic character
    char ch2 = '5';  // Numeric character
    char ch3 = '$';  // Special character
    char ch4 = '\n'; // Newline character

    if (ft_isalnum(ch1)) {
        printf("%c is alphanumeric.\n", ch1);
    } else {
        printf("%c is not alphanumeric.\n", ch1);
    }

    if (ft_isalnum(ch2)) {
        printf("%c is alphanumeric.\n", ch2);
    } else {
        printf("%c is not alphanumeric.\n", ch2);
    }

    if (ft_isalnum(ch3)) {
        printf("%c is alphanumeric.\n", ch3);
    } else {
        printf("%c is not alphanumeric.\n", ch3);
    }

    if (ft_isalnum(ch4)) {
        printf("%c is alphanumeric.\n", ch4);
    } else {
        printf("%c is not alphanumeric.\n", ch4);
    }

    return 0;
} */
