/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:14:16 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:14:17 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*walker;

	if (lst == NULL)
		return (NULL);
	walker = lst;
	while (walker->next != NULL)
		walker = walker->next;
	return (walker);
}

// ******************************* M A N U A L ********************************
// The function ft_lstlast DOES NOT MODIFY the list.
// It returns a pointer to the LAST node of the linked list.
// t_list *walker                helper pointer used to walk through the list
// if (!lst)                     empty list: there is no last node
// walker = lst                  start walking from the head of the list
// while (walker->next != NULL)  continue until reaching the last node
// walker = walker->next         move to the next node like i++ (in strings)
// return (walker)               return the address of the last node
// ******************************* M A N U A L ********************************
