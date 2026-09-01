/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_2_sort_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:02:12 by criredon          #+#    #+#             */
/*   Updated: 2026/08/28 10:20:30 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *stack_a)
{
	t_stack	*node;
	int		min;
	int		position;
	int		min_position;

	node = stack_a;
	min = node->index;
	position = 0;
	min_position = 0;
	while (node)
	{
		if (node->index < min)
		{
			min = node->index;
			min_position = position;
		}
		position++;
		node = node->next;
	}
	return (min_position);
}

static void	move_min(t_stack **stack_a, int position)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (position <= size / 2)
	{
		while (position-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			reverse_rotate_a(stack_a);
	}
}

void	sort_last_three(t_stack **stack_a)
{
	t_stack	*top_node_a;
	int		first;
	int		second;
	int		third;
	int		size;

	top_node_a = *stack_a;
	size = get_stack_size(*stack_a);
	if (size < 2 || check_sorted(top_node_a))
		return ;
	if (size == 2)
		return (swap_a(stack_a));
	first = top_node_a->index;
	second = top_node_a->next->index;
	third = top_node_a->next->next->index;
	if (first > second && first < third)
		swap_a(stack_a);
	else if (first > second && second > third)
		return (swap_a(stack_a), reverse_rotate_a(stack_a));
	else if (first > second && first > third)
		rotate_a(stack_a);
	else if (first < second && first < third)
		return (swap_a(stack_a), rotate_a(stack_a));
	else
		reverse_rotate_a(stack_a);
}

void	sort_simple(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = get_stack_size(*stack_a);
	while (size_a > 3 && !check_sorted(*stack_a))
	{
		move_min(stack_a, find_min(*stack_a));
		push_b(stack_a, stack_b);
		size_a = get_stack_size(*stack_a);
	}
	if (!check_sorted(*stack_a))
		sort_last_three(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}
