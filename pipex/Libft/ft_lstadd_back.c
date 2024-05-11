/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:15:40 by ozini             #+#    #+#             */
/*   Updated: 2024/04/11 12:57:15 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	//El puntero lst es doble porque lo estamos pasando por referencia.
	//Si pasase *lst, entonces no estaría cambiando el puntero en cabeza de lista al llamar a la función.
	t_list *temp;
	//Si la lista está vacía, igualo lst al nuevo nodo.
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	//Si la lista no está vacía, itero hasta el último nodo de la lista.
	while (temp->next != NULL)
		temp = temp->next;
	//Hago que la variable "next" apunte al nuevo nodo.
	temp->next = new;
	
}
