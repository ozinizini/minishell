/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:32:13 by ozini             #+#    #+#             */
/*   Updated: 2023/12/06 12:04:44 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*transformed_string;
	unsigned int	i;

	i = 0;
	transformed_string = (char *)malloc(((int)ft_strlen(s) + 1) * sizeof(char));
	if (transformed_string == NULL)
		return (NULL);
	while (((char *)s)[i] != '\0')
	{
		transformed_string[i] = f(i, s[i]);
		i++;
	}
	transformed_string[i] = '\0';
	return (transformed_string);
}
