/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:13:26 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:13:27 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// ******************************* M A N U A L ********************************
// The function ft_lstnew ONLY creates a single isolated node: (1) allocates
// memory for one node, (2) stores the given content, (3) sets a pointer to the
// end of the list (NULL), and (4) returns the node’s address.
// t_list *newnode; 				type of returned value: a pointer to a node
// newnode = malloc(sizeof(t_list))	behaviour: ask system for memory space
// 									and its address
// if (!newnode), return (NULL)		safety check: if memory is full and
//									malloc failed, stop and return nothing
// newnode->content = content		storage: newnode is the pointer to node,
//									-> access the struct, content is the field
//									inside the node.
// newnode->next = NULL				storage: newnode is the pointer to node,
//									-> access the struct, next is the pointer,
// 									= NULL is the end of the list.
// return (newnode)					returned value: address of the new node.
// ******************************* M A N U A L ********************************