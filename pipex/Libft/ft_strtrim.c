/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:07:19 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 11:00:34 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_beginning(char const *s1, char const *set)
{
	int	position;

	while (*s1 != '\0')
	{
		position = 0;
		while (set[position] != *s1 && set[position] != '\0')
			position++;
		if (position == (int)ft_strlen(set))
			break ;
		s1++;
	}
	return ((char *)s1);
}

static int	trim_end(char const *s1, char const *set, int s1_length)
{
	int		position;

	while (s1_length - 1 >= 0)
	{
		position = 0;
		while (set[position] != s1[s1_length - 1] && set[position] != '\0')
			position++;
		if (position == (int)ft_strlen(set))
			break ;
		s1_length--;
	}
	return (s1_length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_char;
	int		s1_length;

	s1 = trim_beginning(s1, set);
	s1_length = (int)ft_strlen(s1);
	s1_length = trim_end(s1, set, s1_length);
	trimmed_char = (char *)malloc((s1_length + 1) * sizeof(char));
	if (trimmed_char == NULL)
		return (NULL);
	ft_strlcpy(trimmed_char, (char *)s1, s1_length + 1);
	return (trimmed_char);
}

/* int	main(void)
{
	char	cadena[] = "bcaholabbac";
	printf("La cadena %s tras recortar el principio 
	queda así: %s", cadena, ft_strtrim(cadena, "abc"));
} */