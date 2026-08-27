/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:13:44 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:13:46 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// ******************************* M A N U A L ********************************
// The function ft_lstdadd_front DO NOT CREATE nodes, it INSERTS a new node
// at the beginning of a linked list.
// t_list **lst				address of the pointer to the 1st node (head)
// t_list *new				the new node to insert
// new->next = *lst			storage >> new is the pointer to the node (box),
//							-> access the struct, next is the pointer to
//							the next node (box), *lst is the new value that
// 							will appear in the box: the 1st node itself
// *lst = new				storage: the head now is the new node.
// It is important to remember: 
// lst = address of the 1st node
// *lst = the 1st node itsellf (the box) with the content and the pointer
// **lst = the content of the head pointer (content of the 1st box)
// It is important to remember: 
// If the function returns VOID so the edge case protection must be return.
// Return (NULL) should be used exclusively if the function is not VOID.
// There are edge cases to take into account:
// new == NULL --> it will try to access an no-existing node (box)
// In case of *lst == NULL there will not be a crash, since it is a empty list
// and the result will be *lst == NULL, new == NULL.
// ******************************* M A N U A L ********************************