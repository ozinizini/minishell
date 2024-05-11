/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:33:44 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 11:29:39 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_strings;
	size_t	i;
	size_t	total_length;

	i = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	joined_strings = (char *)malloc((total_length + 1) * sizeof(char));
	if (joined_strings == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		joined_strings[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		joined_strings[i] = *s2++;
		i++;
	}
	joined_strings[i] = '\0';
	return (joined_strings);
}

/* int	main(void)
{
	char	*cadena1 = "Hola, me llamo ";
	char	*cadena2 = "Antonio";

	printf("La cadena resultante es: %s", ft_strjoin(cadena1, cadena2));
} */