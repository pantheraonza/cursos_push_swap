/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:14:04 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 21:14:05 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*walker;
	int		i;

	if (lst == NULL)
		return (0);
	i = 0;
	walker = lst;
	while (walker != NULL)
	{
		walker = walker->next;
		i++;
	}
	return (i);
}

// ******************************* M A N U A L ********************************
// The function ft_lstsize DOES NOT MODIFY the list, it ONLY COUNTS how many
// nodes exist in a linked list.
// t_list *walker				helper pointer used to walk through the list
// int i						counter of how many nodes are found
// i = 0						initialize counter at zero
// walker = lst					start walking from the head of the list
// while (walker != NULL)		iterate through every node until the end
// walker = walker->next		move to the next node in the chain
// i++							increase counter for each visited node
// return (i)					return total number of nodes found
// There are NO edge cases to take into account:
// In case of a lst == NULL, then lastnode == NULL and the while will not work.
// ******************************* M A N U A L ********************************
