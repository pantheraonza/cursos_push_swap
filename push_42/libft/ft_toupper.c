/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:02:22 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:02:23 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
//
// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path w/lowercase): Given 'a'\n");
// 	printf("--> Orig %c | Repl %c\n", toupper('a'), ft_toupper('a'));
// 	printf("--> Orig %c | Repl %c\n", toupper('z'), ft_toupper('z'));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Already uppercase, no change): Given 'A'\n");
// 	printf("--> Orig %c | Repl %c\n", toupper('A'), ft_toupper('A'));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Digit, no change): Given '1'\n");
// 	printf("--> Orig %c | Repl %c\n", toupper('1'), ft_toupper('1'));
// 	printf("************************************************************\n");
// 	printf("Test 3 (Symbol just below 'a', no change): Given '`' (96)\n");
// 	printf("--> Orig %d | Repl %d\n", toupper('`'), ft_toupper('`'));
// 	printf("************************************************************\n");
// 	printf("Test 4 (Negative int, EOF-like): Given -1\n");
// 	printf("--> Orig %d | Repl %d\n", toupper(-1), ft_toupper(-1));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The toupper() function converts a lowercase letter to the
// corresponding uppercase letter, if a mapping exists. Other
// characters are returned unchanged.
// RETURN VALUES & ERRORS
// Returns the converted character, cast to an int, or c unchanged if
// no conversion was applicable.
// ******************************* M A N U A L ********************************
