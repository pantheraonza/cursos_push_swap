/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:14:33 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:14:35 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*walker;

	if (lst == NULL || new == NULL)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	walker = *lst;
	while (walker->next != NULL)
		walker = walker->next;
	walker->next = new;
}

// ******************************* M A N U A L ********************************
// The function ft_lstdadd_back DOES NOT CREATE a node, it INSERTS a new node
// at the END of a linked list.
// t_list *walker					helper pointer to walk through the list
// if (!lst), return (NULL)			if list is empty, new node is the 1st node
// walker = *lst;					start the walk from the head of the list
// while (walker->next != NULL)		walk through the list, till its end (NULL)
// walker = walker->next;			move the walkerer pointer to the next node
// 									in the linked list (like i++ in a string)
// walker->next = new;				add the bridge between the lastnode (box)
// 									with the nex (box) --> attach it to the
// 									end of the linked list.
// There are edge cases to take into account:
// ft_lstadd_back requires a valid pointer (lst) to the list to be "walked"
// and a valid node to insert (new). It will crash in case of lst == NULL
// (pointer does not exists), *lst == NULL (empty list), and new == NULL
// (there is no node to insert).
// ******************************* M A N U A L ********************************
