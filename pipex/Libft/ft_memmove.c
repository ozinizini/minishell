/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:08:08 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 13:39:13 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/* void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen((char *)dst) != 0)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
} */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}
/* ChatGPT: The memmove function in C is used to copy a specified number 
of bytes from one memory location to another, 
even if the source and destination regions overlap. Here are some 
examples illustrating edge cases for the memmove function
*/
/*
Mi explicación: La función copia len caracteres de 
la cadena src (source) en el buffer dst (de destino).
Aquí len no tiene en cuenta \0 ni nada por el estilo. 
*/
/* int main() {
    // Example 1: Basic Usage
    char source1[] = "Hello, World!";
    char destination1[20];
	char source2[] = "Hello, World!";
    char destination2[20];
    memmove(destination1, source1, strlen(source1) + 1);
    printf("Example 1: %s\n", destination1);
	//Result:Hello, World!
	ft_memmove(destination2, source2, strlen(source2) + 1);
	printf("My result, ft_memmove: %s\n", destination2);
	//My Result:Hello, World"

    // Example 2: Overlapping regions (destination before source)
    char buffer2[20] = "Hello, World!";
    memmove(buffer2 + 6, buffer2, 6);
    printf("Example 2: %s\n", buffer2);
	//Result:Hello,Hello,!
	char buffer2_ft_memmove[20] = "Hello, World!";
    ft_memmove(buffer2_ft_memmove + 6, buffer2_ft_memmove, 6);
    printf("My result, ft_memmove: %s\n", buffer2_ft_memmove);
	//My result: Hello,Hello,!

    // Example 3: Overlapping regions (source before destination)
    char buffer3[20] = "Hello, World!";
    memmove(buffer3, buffer3 + 6, 7);
    printf("Example 3: %s\n", buffer3);
	//Result: World!World
	char buffer3_ft_memmove[20] = "Hello, World!";
    ft_memmove(buffer3_ft_memmove, buffer3_ft_memmove + 6, 7);
    printf("My result, ft_memmove: %s\n", buffer3_ft_memmove);

    // Example 4: Copying to and from the same buffer with overlap
    char buffer4[20] = "Hello, World!";
    memmove(buffer4 + 6, buffer4, 5);
    printf("Example 4: %s\n", buffer4);
	//Result: Hello,Hellod!
	char buffer4_ft_memmove[20] = "Hello, World!";
    ft_memmove(buffer4_ft_memmove + 6, buffer4_ft_memmove, 5);
    printf("My result, ft_memmove: %s\n", buffer4_ft_memmove);
	//Result: Hello,Hellod!

    // Example 5: Copying zero bytes
    char source5[] = "Hello, World!";
    char destination5[20];
    memmove(destination5, source5, 0);
    printf("Example 5: %s\n", destination5);
	//Result:(empty)

	char source5_ft_memmove[] = "Hello, World!";
    char destination5_ft_memmove[20];
    memmove(destination5_ft_memmove, source5_ft_memmove, 0);
    printf("My result, ft_memmove %s\n", destination5_ft_memmove);
	//Result:(empty)

	//Failed test 42 Málaga
	char source6[] = "";
    char destination6[] = "";
    memmove(destination6, source6, 5);
    printf("Example 5: %s\n", destination6);

    return (0);
}  */