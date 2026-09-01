/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_prepare_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:47:55 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/28 12:25:37 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*current_node;
	t_stack	*runner_node;
	int		smaller_count;

	current_node = stack;
	while (current_node)
	{
		smaller_count = 0;
		runner_node = stack;
		while (runner_node)
		{
			if (runner_node->value < current_node->value)
				smaller_count++;
			runner_node = runner_node->next;
		}
		current_node->index = smaller_count;
		current_node = current_node->next;
	}
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

t_stack	*create_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = num;
	node->index = -1;
	node->next = NULL;
	return (node);
}
