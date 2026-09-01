/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_5_sort_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:02:55 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 19:02:56 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adapt(t_stack **stack_a, t_stack **stack_b, double disorder)
{
	if (disorder < 0.2)
		sort_simple(stack_a, stack_b);
	else if (disorder < 0.5)
		sort_medium(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b);
}
