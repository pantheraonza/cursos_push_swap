/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:14:49 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:14:50 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// ******************************* M A N U A L ********************************
// The function ft_lstdelone DOES NOT modify a linked list structure.
// It deletes ONLY one node safely by freeing its content and the node itself.
// t_list *lst			pointer to the node to be deleted
// void (*del)(void *)	function used to free the node's content
// if (!lst || !del)	safety check: if node/delete function do not exist
// del(lst->content)	delete the content stored inside the node
// free(lst)			free the memory allocated for the node itself
// There are edge cases to take into account:
// ft_lstdelone requires a valid node (lst) and a valid function pointer (del).
// ******************************* M A N U A L ********************************