/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:18:25 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 11:19:52 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		count;
	size_t		needle_len;

	count = 0;
	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && count < len)
	{
		i = 0;
		while (needle[i] == haystack[i] && (count + i) < len
			&& haystack[i] != '\0')
			i++;
		if (i == needle_len)
			return ((char *)haystack);
		haystack++;
		count++;
	}
	return (NULL);
}

//If needle is not found in haystack, return NULL
//If needle is empty, return haystack
//If needle is found in haystack, return the remaining piece of string

/* int	main(void)
{
	char	*cadena = ft_strnstr("aaxx", "xx", 5);
	printf("Returned string: %s\n", cadena);
	char	*cadena2 = strnstr("aaxx", "xx", 5);
	printf("Returned string: %s", cadena2);
	return (0);
} */
