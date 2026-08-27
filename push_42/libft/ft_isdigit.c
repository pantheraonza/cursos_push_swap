/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:11:47 by criredon          #+#    #+#             */
/*   Updated: 2026/06/03 16:11:49 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path with digits): Given '0', '9'\n");
// 	printf("--> Orig %d | Repl %d\n", isdigit('0'), ft_isdigit('0'));
// 	printf("--> Orig %d | Repl %d\n", isdigit('9'), ft_isdigit('9'));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Letter, must be false): Given 'a'\n");
// 	printf("--> Orig %d | Repl %d\n", isdigit('a'), ft_isdigit('a'));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Symbol, must be false): Given '/' (47)\n");
// 	printf("--> Orig %d | Repl %d\n", isdigit('/'), ft_isdigit('/'));
// 	printf("************************************************************\n");
// 	printf("Test 3 (NULL byte): Given '\\0'\n");
// 	printf("--> Orig %d | Repl %d\n", isdigit('\0'), ft_isdigit('\0'));
// 	printf("************************************************************\n");
// 	printf("Test 4 (Ext ASCII via negative signed char): Given -1, 256\n");
// 	printf("--> Orig %d | Repl %d\n", isdigit(-1), ft_isdigit(-1));
// 	printf("--> Orig %d | Repl %d\n", isdigit(256), ft_isdigit(256));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// isdigit() checks for a digit (0 through 9).
// RETURN VALUES & ERRORS
// The values returned are nonzero if the character c falls into the tested
// class, and zero if not. For the purpose of 42 libft project, the return value
// must be: 1 if the character meets the tested condition, 0 if not.
// ******************************* M A N U A L ********************************
