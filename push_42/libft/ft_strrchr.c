/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:03:00 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:03:01 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*str;

// 	str = "hello world";
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Last match, 'l' appears 3 times)\n");
// 	printf("--> Orig %p | Repl %p\n", strrchr(str, 'l'), ft_strrchr(str, 'l'));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Single occurrence): Find 'h'\n");
// 	printf("--> Orig %p | Repl %p\n", strrchr(str, 'h'), ft_strrchr(str, 'h'));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Search for '\\0', must return end pointer)\n");
// 	printf("--> Orig %p | Repl %p\n",
// 		strrchr(str, '\0'), ft_strrchr(str, '\0'));
// 	printf("************************************************************\n");
// 	printf("Test 3 (Char not present): Find 'z'\n");
// 	printf("--> Orig %p | Repl %p\n", strrchr(str, 'z'), ft_strrchr(str, 'z'));
// 	printf("************************************************************\n");
// 	printf("Test 4 (Empty string, search for non-null char)\n");
// 	printf("--> Orig %p | Repl %p\n", strrchr("", 'a'), ft_strrchr("", 'a'));
// 	printf("************************************************************\n");
// 	printf("Test 5 (Match is also the very last character)\n");
// 	printf("--> Orig %p | Repl %p\n", strrchr(str, 'd'), ft_strrchr(str, 'd'));
// 	return (0);
// }
//
// ******************************** M A N U A L ********************************
// DESCRIPTION
// The strrchr() function locates the LAST occurrence of c (converted
// to a char) in the string s. The terminating NULL byte is considered
// part of the string, so searching for '\0' returns a pointer to it.
// RETURN VALUES & ERRORS
// Returns a pointer to the matched byte,
// or NULL if c does not occur in s.
// ******************************* M A N U A L ********************************
