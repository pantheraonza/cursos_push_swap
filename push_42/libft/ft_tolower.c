/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:02:35 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:02:36 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
//
// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path w/uppercase): Given 'A'\n");
// 	printf("--> Orig %c | Repl %c\n", tolower('A'), ft_tolower('A'));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Already lowercase, no change): Given 'a'\n");
// 	printf("--> Orig %c | Repl %c\n", tolower('a'), ft_tolower('a'));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Digit, no change): Given '1'\n");
// 	printf("--> Orig %c | Repl %c\n", tolower('1'), ft_tolower('1'));
// 	printf("************************************************************\n");
// 	printf("Test 3 (Symbol just past 'Z', no change): Given '[' (91)\n");
// 	printf("--> Orig %d | Repl %d\n", tolower('['), ft_tolower('['));
// 	printf("************************************************************\n");
// 	printf("Test 4 (Negative int, EOF-like): Given -1\n");
// 	printf("--> Orig %d | Repl %d\n", tolower(-1), ft_tolower(-1));
// 	return (0);
// }
//
// ******************************** M A N U A L ********************************
// DESCRIPTION
// The tolower() function converts an uppercase letter to the
// corresponding lowercase letter, if a mapping exists. Other
// characters are returned unchanged.
// RETURN VALUES & ERRORS
// Returns the converted character, cast to an int, or c unchanged if
// no conversion was applicable.
// ******************************* M A N U A L ********************************
