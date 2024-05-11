/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:26:29 by ozini             #+#    #+#             */
/*   Updated: 2024/01/03 10:05:41 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
   //lst es el nodo a liberar.
   //del es el puntero a la función utilizada para liberar el contenido del nodo.
   del(lst->content);
   //La función toma como parámetro un nodo 'lst' y libera la memoria del contenido utilizando
   //la función 'del' dada como parámetro, además de liberar el nodo. La memoria de 'next' no deber liberarse.
   free(lst);
    
}