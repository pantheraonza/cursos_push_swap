/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_1_operations_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:06:42 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:06:43 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_node(t_stack **destination, t_stack **source)
{
	t_stack	*node;
	t_stack	*next_node;

	if (!destination || !source || !*source)
		return (0);
	node = *source;
	next_node = node->next;
	*source = next_node;
	node->next = *destination;
	*destination = node;
	return (1);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (push_node(stack_a, stack_b))
		ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (push_node(stack_b, stack_a))
		ft_printf("pb\n");
}
