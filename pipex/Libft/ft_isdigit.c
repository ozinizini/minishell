/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:13:30 by ozini             #+#    #+#             */
/*   Updated: 2023/11/30 11:15:14 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int main() {
    char ch1 = '7';
    char ch2 = 'A';
    char ch3 = '\t'; // Tab character
    char ch4 = '$';

    if (isdigit(ch1)) {
        printf("%c is a digit.\n", ch1);
    } else {
        printf("%c is not a digit.\n", ch1);
    }

    if (isdigit(ch2)) {
        printf("%c is a digit.\n", ch2);
    } else {
        printf("%c is not a digit.\n", ch2);
    }

    if (isdigit(ch3)) {
        printf("%c is a digit.\n", ch3);
    } else {
        printf("%c is not a digit.\n", ch3);
    }

    if (isdigit(ch4)) {
        printf("%c is a digit.\n", ch4);
    } else {
        printf("%c is not a digit.\n", ch4);
    }

    return 0;
}
 */