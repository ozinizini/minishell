/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:33:26 by ozini             #+#    #+#             */
/*   Updated: 2023/12/09 11:33:17 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (dst == src)
		return (dst);
	while (count < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		count++;
	}
	return (dst);
}

/* int main() {
    char source[] = "Hello, memcpy!";
    char destination[20];
    void *test;

    // Using memcpy to copy the content of source to destination
    test = memcpy(destination, source, strlen(source) + 1);

    // Print the result
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
} */
