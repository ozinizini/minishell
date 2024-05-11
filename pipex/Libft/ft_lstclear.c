/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:06:46 by ozini             #+#    #+#             */
/*   Updated: 2024/01/03 11:04:31 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
   //lst: dirección de un puntero a un nodo.
   //del: un puntero a función utilizado para eliminar el contenido de un nodo.
	
   //Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo, utilizando la función
   //’del’ y free(3).
   // Al final, el puntero a la lista debe ser NULL.
	
	//Creo un puntero temporal que apuntará al siguiente nodo que se está borrando.
	t_list  *next_node;

	while(*lst != NULL)
	{
		//Creo el puntero que apunta al siguiente nodo.
		next_node = (*lst)->next;  
		//Elimino el contenido del nodo actual.
		del((*lst)->content);
		//Libero el puntero que apunta a la lista.		
		free(*lst);
		*lst = NULL;
		//Hago que el puntero actual sea igual al siguiente.    
		*lst = next_node;
	}
	
}