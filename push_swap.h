/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:14:40 by criredon          #+#    #+#             */
/*   Updated: 2026/08/27 17:14:41 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int			count_operations (int counter);
int			parse_flags(int argc, char **argv, int *strategy, int *first_num);
int			parse_nums(int argc, char **argv, int first_n, t_stack **stack_a);
void		free_stack(t_stack **stack);
void		assign_indexes(t_stack *stack);
int			get_stack_size(t_stack *stack);
void		add_node_back(t_stack **stack, t_stack *new_node);
t_stack		*create_node(int num);
double		calculate_disorder(t_stack *stack_a);
int			check_sorted(t_stack *stack_a);
void		execute(t_stack **a, t_stack **b, int strategy, double disorder);
void		sort_last_three(t_stack **stack_a);
void		sort_simple(t_stack **stack_a, t_stack **stack_b);
void		sort_medium(t_stack **stack_a, t_stack **stack_b);
void		sort_complex(t_stack **stack_a, t_stack **stack_b);
void		sort_adapt(t_stack **stack_a, t_stack **stack_b, double disorder);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_both(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate_a(t_stack **stack_a);
void		reverse_rotate_b(t_stack **stack_b);
void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
