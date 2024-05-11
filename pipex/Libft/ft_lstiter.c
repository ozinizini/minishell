/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:29:53 by ozini             #+#    #+#             */
/*   Updated: 2024/01/03 14:57:34 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	//lst es el puntero al primer nodo.
	//f es un puntero a la función que utilizará cada nodo.
	
	//Esta función itera la lista y aplica la función f en el contenido de cada nodo.
	//Recordar que el contenido estaba declarado como void *content.
	while (lst != NULL)
	{
		f((lst->content));
		lst = lst->next;
	}
}