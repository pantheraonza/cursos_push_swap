/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_3_operations_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:06:53 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:06:54 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_nodes(t_stack **stack_a)
{
	t_stack	*top_node_a;
	t_stack	*bottom_node_a;

	if (!stack_a || !*stack_a)
		return (0);
	top_node_a = *stack_a;
	if (!top_node_a->next)
		return (0);
	*stack_a = top_node_a->next;
	top_node_a->next = NULL;
	bottom_node_a = *stack_a;
	while (bottom_node_a->next)
		bottom_node_a = bottom_node_a->next;
	bottom_node_a->next = top_node_a;
	return (1);
}

void	rotate_a(t_stack **stack_a)
{
	if (rotate_nodes(stack_a))
	{		count_operations(1);
			ft_printf("ra\n");
	}
}

void	rotate_b(t_stack **stack_b)
{
	if (rotate_nodes(stack_b))
	{	count_operations(1);
		ft_printf("rb\n");
	}
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate_nodes(stack_a))
		if (rotate_nodes(stack_b))
		{	count_operations(1);
			ft_printf("rr\n");
		}
}
