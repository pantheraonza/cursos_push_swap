/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_3_sort_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:02:25 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:02:27 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_stack *stack_b)
{
	t_stack	*current_node;
	int		max;
	int		position;
	int		max_position;

	current_node = stack_b;
	max = current_node->index;
	position = 0;
	max_position = 0;
	while (current_node)
	{
		if (current_node->index > max)
		{
			max = current_node->index;
			max_position = position;
		}
		position++;
		current_node = current_node->next;
	}
	return (max_position);
}

static void	restore_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	size_b;

	while (*stack_b)
	{
		size_b = get_stack_size(*stack_b);
		position = find_max(*stack_b);
		if (position <= size_b / 2)
			while (position-- > 0)
				rotate_b(stack_b);
		else
		{
			position = size_b - position;
			while (position-- > 0)
				reverse_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

static void	push_chunk(t_stack **stack_a, t_stack **stack_b,
	int first_index, int last_index)
{
	t_stack	*top_node_a;
	int		total_to_push;
	int		pushed;

	total_to_push = last_index - first_index + 1;
	pushed = 0;
	while (pushed < total_to_push)
	{
		top_node_a = *stack_a;
		if (!top_node_a)
			return ;
		if (top_node_a->index >= first_index
			&& top_node_a->index <= last_index)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
	}
}

static int	calculate_square_root(int n)
{
	int	square_root;

	square_root = 1;
	while (square_root * square_root < n)
		square_root++;
	return (square_root);
}

void	sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	first_index;
	int	last_index;
	int	chunk_size;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	chunk_size = calculate_square_root(stack_size);
	first_index = 0;
	while (first_index < stack_size)
	{
		last_index = first_index + chunk_size - 1;
		if (last_index >= stack_size)
			last_index = stack_size - 1;
		push_chunk(stack_a, stack_b, first_index, last_index);
		first_index = last_index + 1;
	}
	restore_stack(stack_a, stack_b);
}
