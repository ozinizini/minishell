/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:07:12 by ozini             #+#    #+#             */
/*   Updated: 2023/11/30 11:11:05 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* int main() {
    char ch1 = 'b';
    char ch2 = '3';
    char ch3 = '$';

    if (isalpha(ch1)) {
        printf("%c is an alphabetic character.\n", ch1);
    } else {
        printf("%c is not an alphabetic character.\n", ch1);
    }

    if (isalpha(ch2)) {
        printf("%c is an alphabetic character.\n", ch2);
    } else {
        printf("%c is not an alphabetic character.\n", ch2);
    }

    if (isalpha(ch3)) {
        printf("%c is an alphabetic character.\n", ch3);
    } else {
        printf("%c is not an alphabetic character.\n", ch3);
    }

    return 0;
} */
