/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:26:51 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 11:21:48 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 1;
	while ((unsigned char)*s1 != '\0'
		&& (unsigned char)*s2 != '\0' && count < n)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		count++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/* int main() {
    char str1[] = "abcdef";
    char str2[] = "abc\375xx"; 

//    char str1[] = "abcdefgh";
//    char str2[] = "abcdwxyz"; 

    int letter_count;

    letter_count = 5;
    
    int result = strncmp(str1, str2, letter_count);
    
	printf("Result with strncmp %d:", result);
    if (result < 0) {
        printf("str1 is less than str2\n");
    } else if (result > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str1 is equal to str2\n");
    }

	printf("Mis resultados con ft_strncmp.c\n");

	result = ft_strncmp(str1, str2, letter_count);
    printf("Result with ft_strncmp %d: result", result);
    if (result < 0) {
        printf("str1 is less than str2\n");
    } else if (result > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str1 is equal to str2\n");
    }

    return 0;
}  */
