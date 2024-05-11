/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:39:22 by ozini             #+#    #+#             */
/*   Updated: 2024/05/09 17:25:31 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	total_len = dst_len + src_len;
	while (*src != '\0' && dst_len < dstsize - 1)
	{
		dst[dst_len] = *src;
		src++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (total_len);
}

/* int	main(void) {
    char	destination[15] = "pqrstuvwxyz";
    const	char	*source = "abcdefgh";

    size_t result = strlcat(destination, source, sizeof(destination));

	printf("Size %lu", sizeof(destination));
    printf("Concatenated string: %s\n", destination);
    printf("Total length after concatenation: %zu\n", result);

    return (0);
} */

/* int	main(void)
 
{
    char	destination[13] = "pqrstuvwxyz ";
    const	char	*source = "abcd";

    size_t result = ft_strlcat(destination, source, 1);

	printf("Size %lu", sizeof(destination));
    printf("Concatenated string: %s\n", destination);
    printf("Total length after concatenation: %zu\n", result);

    return (0);
}  */

/* int main()
{

//Empty destination string
char dest[3] = "";
const char *src = "abc";
size_t result = strlcat(dest, src, sizeof(dest));

printf("El resultado es: %lu y el size del buffer de 
destino es %lu. La cadena es %s\n", result, sizeof(dest),dest);

//Empty Source String
char dest2[10] = "123";
const char *src2 = "";
size_t result2 = strlcat(dest2, src2, sizeof(dest2));

printf("El resultado es: %lu y el size del buffer de destino 
es %lu. La cadena es %s\n", result2, sizeof(dest2),dest2);

//Destination String Just Fits. 
char dest3[5] = "123";
const char *src3 = "abc";
size_t result3 = strlcat(dest3, src3, sizeof(dest3));
printf("El resultado es: %lu y el size del buffer de destino 
es %lu. La cadena es %s\n", result3, sizeof(dest3), dest3);

//Destination String Larger Than Specified Size:
char dest4[5] = "12345";
const char *src4 = "abc";
size_t result4 = strlcat(dest4, src4, sizeof(dest4));
printf("El resultado es: %lu y el size del buffer de destino 
es %lu. La cadena es %s\n", result4, sizeof(dest4), dest4);

//Source String Larger Than Remaining Space
char dest5[8] = "123";
const char *src5 = "abcdefgh";
size_t result5 = strlcat(dest5, src5, sizeof(dest5));
printf("El resultado es: %lu y el size del buffer de destino 
es %lu. La cadena es %s\n", result5, sizeof(dest5), dest5);

//Destination String Null-Terminated
char dest6[10] = "123\0xxxx";
const char *src6 = "abc";
size_t result6 = strlcat(dest6, src6, sizeof(dest6));
printf("El resultado es: %lu y el size del buffer de destino 
es %lu. La cadena es %s\n", result6, sizeof(dest6), dest6);
}
*/
