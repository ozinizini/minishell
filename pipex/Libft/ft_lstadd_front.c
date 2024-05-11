/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:30:08 by ozini             #+#    #+#             */
/*   Updated: 2024/01/03 14:37:31 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	//El campo next del nuevo nodo apuntará a la misma dirección que el puntero en cabeza de lista. 
	//Luego haríamos que el puntero en cabeza apuntase al nuevo nodo.
	//lst es un puntero doble porque estoy pasando el puntero lst por referencia,
	//de modo que la cabeza de la lista desde fuera de la función se actualice.
	new->next = *lst;
	*lst = new;
}
