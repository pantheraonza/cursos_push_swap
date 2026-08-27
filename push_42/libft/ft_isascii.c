/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:00:35 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:00:36 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path with boundaries): Given 0, 127\n");
// 	printf("--> Orig %d | Repl %d\n", isascii(0), ft_isascii(0));
// 	printf("--> Orig %d | Repl %d\n", isascii(127), ft_isascii(127));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Just past boundary): Given 128\n");
// 	printf("--> Orig %d | Repl %d\n", isascii(128), ft_isascii(128));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Negative): Given -1\n");
// 	printf("--> Orig %d | Repl %d\n", isascii(-1), ft_isascii(-1));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The isascii() function tests for an ASCII character, which is any
// character with a value from 0 (zero) to 0x7F (127) inclusive.
// RETURN VALUES & ERRORS
// The values returned are nonzero if the character c falls into the
// tested class, and zero if not. For libft purposes, the return value
// must be exactly 1 if true, 0 if false.
// ******************************* M A N U A L ********************************
