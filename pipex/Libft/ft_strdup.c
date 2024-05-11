/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:12 by ozini             #+#    #+#             */
/*   Updated: 2023/12/02 13:55:59 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		longitud_cadena;

	longitud_cadena = 0;
	while (*(src + longitud_cadena) != '\0')
		longitud_cadena++;
	longitud_cadena++;
	temp = (char *) malloc(longitud_cadena * sizeof (char));
	if (temp == NULL)
		return (NULL);
	longitud_cadena = 0;
	while (*(src + longitud_cadena) != '\0')
	{
		temp[longitud_cadena] = *(src + longitud_cadena);
		longitud_cadena ++;
	}
	temp[longitud_cadena] = '\0';
	return ((char *)temp);
}

/* int	main(void)
{
	char	*cadena_devuelta;
	char	cadena[13] = "Hasta luego.";

	cadena_devuelta = ft_strdup(cadena);

	printf("La cadena es: %s", cadena_devuelta);
    
	while(*cadena_devuelta != '\0')
	{
		write(1, cadena_devuelta, 1);
		cadena_devuelta++;
	}
}  */