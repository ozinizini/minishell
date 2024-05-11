/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:12:37 by ozini             #+#    #+#             */
/*   Updated: 2024/01/02 10:47:58 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	position_substr;

	position_substr = 0;
	while (s[position_substr] != '\0')
		position_substr++;
	if (position_substr == 0 || start > position_substr)
		return (ft_strdup(""));
	if (position_substr - start >= len)
		substr = (char *)malloc((len + 1) * sizeof(char));
	else
		substr = (char *)malloc(((position_substr - start) + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	position_substr = 0;
	while (position_substr < len && s[start] != '\0')
		substr[position_substr++] = s[start++];
	substr[position_substr] = '\0';
	return (substr);
}

/* int main()
{
	char cadena[] = "Omar Zini";
	printf("La cadena resultante es: %s", ft_substr(cadena, 0, 6));
} */