/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:03:53 by criredon          #+#    #+#             */
/*   Updated: 2026/06/24 15:03:54 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Equal strings, full n): \"abc\" vs \"abc\", n=3\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		strncmp("abc", "abc", 3), ft_strncmp("abc", "abc", 3));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Differ within n): \"abc\" vs \"abd\", n=3\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		strncmp("abc", "abd", 3), ft_strncmp("abc", "abd", 3));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Differ AFTER n, must compare equal): n=2\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		strncmp("abc", "abd", 2), ft_strncmp("abc", "abd", 2));
// 	printf("************************************************************\n");
// 	printf("Test 3 (n=0, always equal regardless of content)\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		strncmp("xyz", "abc", 0), ft_strncmp("xyz", "abc", 0));
// 	printf("************************************************************\n");
// 	printf("Test 4 (Different lengths, shorter string wins early)\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		strncmp("ab", "abc", 5), ft_strncmp("ab", "abc", 5));
// 	printf("************************************************************\n");
// 	printf("Test 5 (Extended ASCII byte, unsigned char comparison)\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		strncmp("\xE9", "\x41", 1), ft_strncmp("\xE9", "\x41", 1));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The strncmp() function compares at most the first n bytes of s1 and
// s2, treating each byte as unsigned char.
// RETURN VALUES & ERRORS
// Returns an int less than, equal to, or greater than zero if s1 is
// found to be less than, equal to, or greater than s2 (within the
// first n bytes).
// ******************************* M A N U A L ********************************