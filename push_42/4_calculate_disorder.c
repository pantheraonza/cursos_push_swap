/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_calculate_disorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:47:39 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 21:22:01 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_inversions(t_stack *stack)
{
    t_stack *current_node;
    t_stack *runner_node;
    int		inversions;

    inversions = 0;
    current_node = stack;
    while(current_node)
    {
        runner_node = current_node->next;
        while(runner_node)
        {
            if(current_node->value > runner_node->value)
                inversions++;
            runner_node = runner_node->next;
        }
        current_node = current_node->next;
    }
    return (inversions);
}

double	calculate_disorder(t_stack *stack_a)
{
    int	size;
    int	inversions;
   	int	max_inversions;

    size = get_stack_size(stack_a);
    if (size < 2)
        return(0.0);
    inversions = count_inversions(stack_a);
    max_inversions = ((long long)size * (size - 1)) / 2;
    if (max_inversions == 0)
        return(0.0);
    return ((double)inversions / (double)max_inversions);
}

int check_sorted(t_stack *stack_a)
{
    if (!stack_a)
        return(1);
    while (stack_a->next)
    {
        if(stack_a->value > stack_a->next->value)
            return(0);
        stack_a = stack_a->next;
    }
    return (1);
}
