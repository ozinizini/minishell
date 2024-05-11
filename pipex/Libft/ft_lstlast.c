/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:01:53 by ozini             #+#    #+#             */
/*   Updated: 2024/01/03 14:32:36 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	//Si la lista está vacía, devuelvo NULL.
	if (lst == NULL)
		return (NULL);
	//Si la lista no está vacía tengo que progresar
	//por ella.
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
