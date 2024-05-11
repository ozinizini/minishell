/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:03:49 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 11:05:03 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/* int main() {
    char buffer[12];

    // Initialize the buffer with some data
    strcpy(buffer, "Hello World");

    // Display the content before using bzero
    printf("Before bzero: %s\n", buffer);

    // Display sizeofbuffer

    printf("The size of the buffer is %lu", sizeof(buffer));

    printf("The size of a char is %lu", sizeof(char));

    // Use bzero to zero out the buffer
    bzero(buffer, sizeof(buffer));

    // Display the content after using bzero
    printf("After bzero: %s\n", buffer);

    return 0;
} */

/* int main() {
    char buffer[12];

    // Initialize the buffer with some data
    strcpy(buffer, "Hello World");

    // Display the content before using bzero
    printf("Before bzero: %s\n", buffer);

    // Display sizeofbuffer

    printf("The size of the buffer is %lu", sizeof(buffer));

    printf("The size of a char is %lu", sizeof(char));

    // Use bzero to zero out the buffer
    bzero(buffer, sizeof(buffer));

    // Display the content after using bzero
    printf("After bzero: %s\n", buffer);

    return 0;
} */
