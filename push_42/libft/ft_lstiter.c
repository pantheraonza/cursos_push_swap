/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:15:53 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:15:55 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*walker;

	if (lst == NULL || f == NULL)
		return ;
	walker = lst;
	while (walker != NULL)
	{
		f(walker->content);
		walker = walker->next;
	}
}

// ******************************* M A N U A L ********************************
// The function ft_lstiter DOES NOT create, delete or modify the linked list.
// It APPLIES the function 'f' to the content of every node.
// t_list *walker			helper pointer used to walk through the list
// void (*f)(void *)		function applied to each node's content
// if (!lst || !f)			if list or function does not exist
// walker = lst				start the walk from the head of the list
// while (walker != NULL)	walk through every node until the end (NULL)
// f(walker->content)		apply the function to the node content
// walker = walker->next	move the walker to the next node
// There are edge cases to take into account:
// ft_lstiter requires a valid list (lst) and a valid function (f).
// ******************************* M A N U A L ********************************
