/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_1_execute_strategy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:01:58 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:01:59 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute(t_stack **a, t_stack **b, int strategy, double disorder)
{
	int	size_a;

	size_a = get_stack_size(*a);
	if (strategy == 1)
		sort_simple(a, b);
	else if (strategy == 2)
		sort_medium(a, b);
	else if (strategy == 3)
		sort_complex(a, b);
	else if (strategy == 4)
		sort_adapt(a, b, disorder);
	else if (size_a <= 3)
		sort_last_three(a);
	else if (size_a <= 5)
		sort_simple(a, b);
	else
		sort_adapt(a, b, disorder);
}
