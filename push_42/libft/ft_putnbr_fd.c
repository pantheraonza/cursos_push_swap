/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:03:45 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 17:03:46 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	if (fd < 0)
		return ;
	number = n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("Tests with Replicated Function\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): print number -4242\n");
// 	ft_putstr_fd("--> Repl: ", 1);
// 	ft_putnbr_fd(-4242, 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }
