/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:00:20 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:00:21 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path w/digits & letters): Given '9', 'a', 'M'\n");
// 	printf("--> Orig %d | Repl %d\n", isalnum('9'), ft_isalnum('9'));
// 	printf("--> Orig %d | Repl %d\n", isalnum('a'), ft_isalnum('a'));
// 	printf("--> Orig %d | Repl %d\n", isalnum('M'), ft_isalnum('M'));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Space, must be false): Given ' '\n");
// 	printf("--> Orig %d | Repl %d\n", isalnum(' '), ft_isalnum(' '));
// 	printf("************************************************************\n");
// 	printf("Test 3 (Symbol between '9' and 'A'): Given ':' (58)\n");
// 	printf("--> Orig %d | Repl %d\n", isalnum(':'), ft_isalnum(':'));
// 	printf("************************************************************\n");
// 	printf("Test 4 (Extended ASCII via negative signed char): Given -1\n");
// 	printf("--> Orig %d | Repl %d\n", isalnum(-1), ft_isalnum(-1));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The isalnum() function tests for any character for which isalpha()
// or isdigit() is true — that is, any letter ('A'-'Z', 'a'-'z') or
// any digit ('0'-'9').
// RETURN VALUES & ERRORS
// Nonzero if c falls into the tested class, zero if not. For libft
// purposes, the return value must be exactly 1 if true, 0 if false.
// ******************************* M A N U A L ********************************
