/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parse_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:23:44 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/25 13:11:56 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_duplicates(t_stack *stack_a, int num)
{
    while (stack_a)
    {
        if (stack_a->value == num)
            return(1);
        stack_a = stack_a->next;
    }
    return (0);
}

static int	ft_is_valid_number(const char *str, int *out_val)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str || !str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = (res * 10) + (str[i] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (0);
		i++;
	}
	return ((*out_val = ((int)res * (int)sign)), 1);
}

static int	process_nums(char *token, t_stack **stack_a)
{
	int		value;
	t_stack	*new_node;

	if (!ft_is_valid_number(token, &value))
		return (0);
	if (check_duplicates(*stack_a, value))
		return (0);
	new_node = create_node(value);
	if (!new_node)
		return (0);
	add_node_back(stack_a, new_node);
	return (1);
}

static void free_split(char **split)
{
    int i;
    
    if (!split)
        return ;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int parse_nums(int argc, char **argv, int first_n, t_stack **stack_a)
{
	char **nums;
    int i;
    int j;

    i = first_n;
    while (i < argc)
    {
        nums = ft_split(argv[i], ' ');
    	if (!nums || !*nums)
		{
			free_split(nums);
			return (0);
		}
		j = 0;
		while (nums[j])
		{
			if (!process_nums(nums[j], stack_a))
				return (free_split(nums), 0);
			j++;
		}
		free_split(nums);
		i++;
	}
	return (1);
}
