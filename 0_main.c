/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:02:22 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/25 13:22:58 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(t_stack **stack_a)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack_a);
}
int	count_operations(int counter)
{
	static int total;

	if (counter == 0)
		total = 0;
	if (counter == 1)
		total += 1;
	if (counter == -1)
	{
		ft_putstr_fd("Operations counter: ", 2);
		ft_putnbr_fd(total, 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		strategy;
	int		first_n;
	double	disorder;
	
	stack_a = NULL;
	stack_b = NULL;
	strategy = 0;
	count_operations(0);
	if (argc < 2)
		return (0);
	if (!parse_flags(argc, argv, &strategy, &first_n))
		return (handle_error(&stack_a), 1);
	if (!parse_nums(argc, argv, first_n, &stack_a))
		return (handle_error(&stack_a), 1);
	assign_indexes(stack_a);
	if (check_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	disorder = calculate_disorder(stack_a);
	execute(&stack_a, &stack_b, strategy, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (ft_strncmp(argv[1], "--counter", 10) == 0)
		count_operations(-1);
	return (0);
}
