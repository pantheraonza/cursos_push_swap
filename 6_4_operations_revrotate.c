/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_4_operations_revrotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:07:06 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:07:07 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_nodes(t_stack **stack_a)
{
	t_stack	*before_bottom_node_a;
	t_stack	*bottom_node_a;

	if (!stack_a || !*stack_a)
		return (0);
	before_bottom_node_a = *stack_a;
	if (!before_bottom_node_a->next)
		return (0);
	while (before_bottom_node_a->next->next)
		before_bottom_node_a = before_bottom_node_a->next;
	bottom_node_a = before_bottom_node_a->next;
	before_bottom_node_a->next = NULL;
	bottom_node_a->next = *stack_a;
	*stack_a = bottom_node_a;
	return (1);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	if (reverse_nodes(stack_a))
	{		count_operations(1);
			ft_printf("rra\n");
	}
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (reverse_nodes(stack_b))
	{		count_operations(1);
			ft_printf("rrb\n");
	}
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (reverse_nodes(stack_a))
		if (reverse_nodes(stack_b))
		{			count_operations(1);
					ft_printf("rrr\n");
		}
}
