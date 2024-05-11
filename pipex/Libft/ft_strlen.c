/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:26:56 by ozini             #+#    #+#             */
/*   Updated: 2023/12/03 12:45:11 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

/* int main() {
    // Example 1: Basic usage
    char str1[] = "Hello, World!";
    printf("Length of str1: %zu\n", strlen(str1));

    // Example 2: Empty string
    char str2[] = "";
    printf("Length of str2: %zu\n", strlen(str2));

    // Example 3: String with embedded null characters
    char str3[] = "Embedded\0Null";
    printf("Length of str3: %zu\n", strlen(str3));

    // Example 4: String with newline character
    char str4[] = "New\nLine";
    printf("Length of str4: %zu\n", strlen(str4));

    printf("Resultados con mi ft_strlen \n");

        // Example 1: Basic usage
    char str5[] = "Hello, World!";
    printf("Length of str5: %zu\n", ft_strlen(str5));

    // Example 2: Empty string
    char str6[] = "";
    printf("Length of str6: %zu\n", ft_strlen(str6));

    // Example 3: String with embedded null characters
    char str7[] = "Embedded\0Null";
    printf("Length of str7: %zu\n", ft_strlen(str7));

    // Example 4: String with newline character
    char str8[] = "New\nLine";
    printf("Length of str8: %zu\n", ft_strlen(str8));

    return 0;
} */
