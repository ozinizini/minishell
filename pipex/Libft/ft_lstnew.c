/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:26:35 by ozini             #+#    #+#             */
/*   Updated: 2024/05/02 10:27:08 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;
	//Reserva de memoria del nodo y comprobación.
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	//El contenido del nodo (content, puntero de tipo void), lo igualo al contenido de content.
	//La variable "next" del nodo tiene que apuntar a NULL.
	new->content = content;
	new->next = NULL;
	return (new);
}
