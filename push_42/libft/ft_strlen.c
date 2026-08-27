/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:01:03 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:01:04 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): Given \"hello\", \"a b c\"\n");
// 	printf("--> Orig %zu | Repl %zu\n", strlen("hello"), ft_strlen("hello"));
// 	printf("--> Orig %zu | Repl %zu\n",
// 		strlen("a b c"), ft_strlen("a b c"));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Empty string): Given \"\"\n");
// 	printf("--> Orig %zu | Repl %zu\n", strlen(""), ft_strlen(""));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Long string, > 100 chars)\n");
// 	printf("--> Orig %zu | Repl %zu\n",
// 		strlen("0123456789012345678901234567890123456789"
// 			"0123456789012345678901234567890123456789"
// 			"0123456789012345678901234567890123456789"
// 			"01234567890123456789"),
// 		ft_strlen("0123456789012345678901234567890123456789"
// 			"0123456789012345678901234567890123456789"
// 			"0123456789012345678901234567890123456789"
// 			"01234567890123456789"));
// 	printf("************************************************************\n");
// 	printf("Improvements to the Original Function\n");
// 	printf("Given NULL as an input for the Replicated Function: %zu\n",
// 		ft_strlen(NULL));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The strlen() function calculates the length of the string s,
// excluding the terminating NULL byte ('\0').
// RETURN VALUES & ERRORS
// Returns the number of bytes in the string s. Behaviour is undefined
// if s is not NULL-terminated, or if s is NULL.
// ******************************* M A N U A L ********************************
