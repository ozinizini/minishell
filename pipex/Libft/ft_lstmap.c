/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:05:44 by ozini             #+#    #+#             */
/*   Updated: 2024/01/03 13:48:36 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    //lst: puntero a un nodo. Puntero en cabeza de lista.
    //f: la dirección de un puntero a una función usada en la iteración de cada elemento de la lista.
    //del: un puntero a función utilizado para eliminar el contenido de un nodo, si es necesario.
    
    //Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo. 
    //Crea una lista resultante de la aplicación correcta y sucesiva de la función.
    //’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar el contenido de un nodo, si hace falta.
    
    //Tengo que crear una nueva lista. La eliminación del nodo sólo tiene lugar si 

    t_list  *new_list;
    t_list  *new_node;
    void    *new_node_content;

    //El puntero a la nueva lista apunta a NULL ya que la lista está vacía.
    new_list = NULL;
    while(lst != NULL)
    {
        new_node_content = f(lst->content);
        new_node = ft_lstnew(new_node_content);
        //Controlar que ft_lstnew no haya devuelto un NULL por error de asignación de memoria.
        if (!new_node)
        {
            del(new_node_content);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_node);
        lst = lst->next;
    }

    return (new_list);

}