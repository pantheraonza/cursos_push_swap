/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_detect_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:29:16 by criredon          #+#    #+#             */
/*   Updated: 2026/08/25 16:29:18 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_strategy(char *arg, int *strategy)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		*strategy = 1;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		*strategy = 2;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		*strategy = 3;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		*strategy = 4;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, int *strategy, int *first_num)
{
	int	i;

	i = 1;
	if (ft_strncmp(argv[1], "--counter", 10) == 0)
		i++;
	if (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (!set_strategy(argv[i], strategy))
			return (0);
		i++;
	}
	if (i == argc)
		return (0);
	*first_num = i;
	return (1);
}
