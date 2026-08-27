/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_4_sort_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:02:39 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:02:41 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_power_of_two(int bit)
{
	int	power;

	power = 1;
	while (bit > 0)
	{
		power = power * 2;
		bit--;
	}
	return (power);
}

static void	sort_current_bit(t_stack **stack_a, t_stack **stack_b, int bit)
{
	t_stack	*top_node_a;
	int		size_a;
	int		power;
	int		i;

	size_a = get_stack_size(*stack_a);
	power = calculate_power_of_two(bit);
	i = 0;
	while (i < size_a)
	{
		top_node_a = *stack_a;
		if (((top_node_a->index / power) % 2) == 1)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

static int	calculate_required_bits(int stack_size)
{
	int	required_bits;
	int	max_index;

	max_index = stack_size - 1;
	required_bits = 0;
	while ((max_index >> required_bits) != 0)
		required_bits++;
	return (required_bits);
}

void	sort_complex(t_stack **stack_a, t_stack **stack_b)
{
	int	bit;
	int	max_bits;

	max_bits = calculate_required_bits(get_stack_size(*stack_a));
	bit = 0;
	while (bit < max_bits)
	{
		sort_current_bit(stack_a, stack_b, bit);
		bit++;
	}
}
