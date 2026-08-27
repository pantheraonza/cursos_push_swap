/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:15:07 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:15:08 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*walker;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	walker = *lst;
	while (walker != NULL)
	{
		next = walker->next;
		ft_lstdelone(walker, del);
		walker = next;
	}
	*lst = NULL;
}

// ******************************* M A N U A L ********************************
// The function ft_lstclear DOES NOT modify nodes individually,
// it deletes the ENTIRE linked list safely.
// t_list *walker			helper pointer used to walk through the list
// t_list *next				temporary pointer to store next node safely
// if (!lst || !del)		if list pointer or delete function does not exist
// walker = *lst            start walking from the head of the list
// while (walker != NULL)	iterate through all nodes until the end
// next = walker->next		store next node before deleting current one
// ft_lstdelone(walker, del)delete current node using reusable function
// walker = next			move walker pointer to next node
// *lst = NULL				set pointer to NULL after full deletion
// There are edge cases to take into account:
// ft_lstclear will do nothing if lst == NULL (pointer does not exist),
// *lst == NULL (empty list), or del == NULL (there is no valid function to
// free the node's content).
// Other important things to know:
// Must store "next" BEFORE freeing the node, otherwise the rest of the
// list is lost (memory leak).
// ******************************* M A N U A L ********************************