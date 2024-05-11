/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:23:31 by ozini             #+#    #+#             */
/*   Updated: 2023/11/30 11:24:28 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int main() {
    char ch1 = 'A';    // Printable uppercase letter
    char ch2 = ' ';    // Printable space character
    char ch3 = '\t';   // Non-printable tab character
    char ch4 = 127;    // Non-printable control character (DEL)

    if (isprint(ch1)) {
        printf("%c is a printable character.\n", ch1);
    } else {
        printf("%c is not a printable character.\n", ch1);
    }

    if (isprint(ch2)) {
        printf("%c is a printable character.\n", ch2);
    } else {
        printf("%c is not a printable character.\n", ch2);
    }

    if (isprint(ch3)) {
        printf("%c is a printable character.\n", ch3);
    } else {
        printf("%c is not a printable character.\n", ch3);
    }

    if (isprint(ch4)) {
        printf("%c is a printable character.\n", ch4);
    } else {
        printf("%c is not a printable character.\n", ch4);
    }

    if (ft_isprint(ch1)) {
        printf("%c is a printable character.\n", ch1);
    } else {
        printf("%c is not a printable character.\n", ch1);
    }

    if (ft_isprint(ch2)) {
        printf("%c is a printable character.\n", ch2);
    } else {
        printf("%c is not a printable character.\n", ch2);
    }

    if (ft_isprint(ch3)) {
        printf("%c is a printable character.\n", ch3);
    } else {
        printf("%c is not a printable character.\n", ch3);
    }

    if (ft_isprint(ch4)) {
        printf("%c is a printable character.\n", ch4);
    } else {
        printf("%c is not a printable character.\n", ch4);
    }


    return 0;
} */
