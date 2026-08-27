/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_2_operations_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:06:32 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:06:33 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_nodes(t_stack **stack_a)
{
	t_stack	*upper_node;
	t_stack	*lower_node;

	if (!stack_a || !*stack_a)
		return (0);
	upper_node = *stack_a;
	lower_node = upper_node->next;
	if (!lower_node)
		return (0);
	upper_node->next = lower_node->next;
	lower_node->next = upper_node;
	*stack_a = lower_node;
	return (1);
}

void	swap_a(t_stack **stack_a)
{
	if (swap_nodes(stack_a))
		ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	if (swap_nodes(stack_b))
		ft_printf("sb\n");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	if (swap_nodes(stack_a))
		if (swap_nodes(stack_b))
			ft_printf("ss\n");
}
