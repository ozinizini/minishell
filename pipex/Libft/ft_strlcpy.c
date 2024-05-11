/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:53:46 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 11:23:45 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/* int main()
{	
	char destination[50];
	char destination2[50];
	char destination3[50];
	char destination4[50];
	char destination5[50];
	char destination6[50];
	printf("Mis resultados con ft_strlcpy \n");
	printf("El resultado de strlcpy es %zu y la cadena es %s\n", 
	ft_strlcpy(destination, "aaa", 0), destination);
	printf("El resultado de strlcpy es %zu y la cadena es %s\n", 
	ft_strlcpy(destination2, "aaa", 2), destination2);
	printf("El resultado de strlcpy es %zu y la cadena es %s\n", 
	ft_strlcpy(destination3, "aaa", 3), destination3);
	
	printf("Resultados con strlcpy \n");
	printf("El resultado de strlcpy es %zu y la cadena es %s\n", 
	strlcpy(destination4, "aaa", 0), destination4);
	printf("El resultado de strlcpy es %zu y la cadena es %s\n", 
	strlcpy(destination5, "aaa", 2), destination5);
	printf("El resultado de strlcpy es %zu y la cadena es %s\n", 
	strlcpy(destination6, "aaa", 3), destination6);
} */

/* int main()
{
    //Source String Length Exceeds Destination Size:
    char source[] = "This is along string";
    char destination[10];
    size_t result = ft_strlcpy(destination, source, sizeof(destination));
    printf("La cadena devuelta es: %s y el valor devuelto es %zu", 
	destination, result);
    // The result will be truncated to fit the destination size, 
	and it won't be null-terminated.

    //Empty Source String:
    char source2[] = "";
    char destination2[10];
    result = ft_strlcpy(destination2, source2, sizeof(destination2));
    printf("La cadena devuelta es: %s y el valor devuelto es %zu", 
	destination2, result);
    // The result will be an empty string, and the null terminator 
	will be present.

    //Equal Source and Destination Size:
    char source3[] = "ShortStr";
    char destination3[9];
    result = ft_strlcpy(destination3, source3, sizeof(destination3));
    printf("La cadena devuelta es: %s y el valor devuelto es %zu", 
	destination3, result);
    // The entire source string will fit in the destination, 
	including the null terminator.
} */

/*
int main()
{
    //Source String Length Exceeds Destination Size:
    char source[] = "This is along string";
    char destination[10];
	size_t result = strlcpy(destination, source, sizeof(destination));
    printf("La cadena devuelta es: %s y el valor devuelto es %zu", 
	destination, result);
    // The result will be truncated to fit the destination size, 
	and it won't be null-terminated.

    //Empty Source String:
    char source2[] = "";
    char destination2[10];
    result = strlcpy(destination2, source2, sizeof(destination2));
    printf("La cadena devuelta es: %s y el valor devuelto es %zu", 
	destination2, result);
    // The result will be an empty string, and the null terminator 
	will be present.

    //Equal Source and Destination Size:
    char source3[] = "ShortStr";
    char destination3[9];
    result = strlcpy(destination3, source3, sizeof(destination3));
    printf("La cadena devuelta es: %s y el valor devuelto es %zu", 
	destination3, result);
    // The entire source string will fit in the destination, 
	including the null terminator.

    //Null Pointers
    //char* source4 = NULL;
   // char destination4[10];
   // strlcpy(destination4, source4, sizeof(destination4));
    // The result will be an empty string, and the null 
	terminator will be present.

}*/