/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:00:47 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:00:49 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path with boundaries): Given ' ', 'A', '~'\n");
// 	printf("--> Orig %d | Repl %d\n", isprint(' '), ft_isprint(' '));
// 	printf("--> Orig %d | Repl %d\n", isprint('A'), ft_isprint('A'));
// 	printf("--> Orig %d | Repl %d\n", isprint('~'), ft_isprint('~'));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Out of boudaries, must be false): Given '\\t', DEL\n");
// 	printf("--> Orig %d | Repl %d\n", isprint(127), ft_isprint(127));
// 	printf("--> Orig %d | Repl %d\n", isprint('\t'), ft_isprint('\t'));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The isprint() function tests for any printable character, including
// space (' '). A printable character is one in the range 0x20 (32) to
// 0x7E (126) inclusive.
// RETURN VALUES & ERRORS
// Nonzero if c falls into the tested class, zero if not. For libft
// purposes, the return value must be exactly 1 if true, 0 if false.
// ******************************* M A N U A L ********************************
