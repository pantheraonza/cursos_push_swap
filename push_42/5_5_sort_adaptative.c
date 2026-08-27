/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_5_sort_adaptative.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:02:55 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:02:56 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	repair_order(t_stack **stack_a)
{
	t_stack	*top_node_a;
	int		size;
	int		moviments;

	size = get_stack_size(*stack_a);
	moviments = size;
	while (moviments > 0 && !check_sorted(*stack_a))
	{
		top_node_a = *stack_a;
		if (top_node_a->next
			&& top_node_a->index > top_node_a->next->index)
			swap_a(stack_a);
		rotate_a(stack_a);
		moviments--;
	}
}

void	sort_adapt(t_stack **stack_a, t_stack **stack_b, double disorder)
{
	if (disorder < 0.2)
	{
		repair_order(stack_a);
		if (!check_sorted(*stack_a))
			sort_medium(stack_a, stack_b);
	}
	else if (disorder < 0.5)
		sort_medium(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b);
}
