/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:05:44 by ozini             #+#    #+#             */
/*   Updated: 2024/05/13 13:41:23 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_node_content;

	new_list = NULL;
	new_node = NULL;
	new_node_content = NULL;
	while (lst != NULL)
	{
		new_node_content = f(lst->content);
		new_node = ft_lstnew(new_node_content);
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
