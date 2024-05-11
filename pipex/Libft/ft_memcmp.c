/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:52:47 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 11:12:23 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (0);
	while (count < n - 1)
	{
		if (*((unsigned char *)s1) - *((unsigned char *)s2) != 0)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
		count++;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}

/* int main() {
    char str1[] = "atoms\0\0\0\0";
    char str2[] = "atoms\0abc";
    int result;
	int result2;

    // Compare the first 5 characters of str1 and str2
    result = memcmp(str1, str2, 8);
	result2 = ft_memcmp(str1, str2, 8);

    if (result == 0) {
        printf("The first 5 characters are equal.\n");
    } else if (result < 0) {
        printf("The first differing character in str1 is smaller.\n");
    } else {
        printf("The first differing character in str1 is larger.\n");
    }

    return 0;
} */