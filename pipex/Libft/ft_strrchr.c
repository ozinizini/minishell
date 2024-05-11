/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:31:18 by ozini             #+#    #+#             */
/*   Updated: 2024/01/02 10:47:48 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			pos = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		s = s + i;
	else
	{
		if (s[0] != (unsigned char)c && pos == 0)
			return (NULL);
		else
			s = s + pos;
	}
	return ((char *)s);
}

/* int main()
{
	printf ("La cadena es: %s", ft_strrchr("Omar \nZini \nZini", 'x'));
	printf ("\nLa cadena es: %s", strrchr("Omar \nZini \nZini", 'x'));
} */
