/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:02:47 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:02:48 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	*str;
//
// 	str = "Hello World";
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): Find 'o' in \"hello world\"\n");
// 	printf("--> Orig %p | Repl %p\n", strchr(str, 'o'), ft_strchr(str, 'o'));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Search for '\\0', must return end pointer)\n");
// 	printf("--> Orig %p | Repl %p\n", strchr(str, '\0'), ft_strchr(str, '\0'));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Char not present): Find 'z' in \"hello world\"\n");
// 	printf("--> Orig %p | Repl %p\n", strchr(str, 'z'), ft_strchr(str, 'z'));
// 	printf("************************************************************\n");
// 	printf("Test 3 (Empty string, search for non-null char)\n");
// 	printf("--> Orig %p | Repl %p\n", strchr("", 'a'), ft_strchr("", 'a'));
// 	printf("************************************************************\n");
// 	printf("Test 4 (c as int > 255, must be truncated like a char)\n");
// 	printf("--> Orig %p | Repl %p\n",
// 		strchr(str, 'o' + 256), ft_strchr(str, 'o' + 256));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The strchr() function locates the first occurrence of c (converted
// to a char) in the string s. The terminating NULL byte is considered
// part of the string, so searching for '\0' returns a pointer to it.
// RETURN VALUES & ERRORS
// Returns a pointer to the matched byte, or NULL if c does not occur in s.
// ******************************* M A N U A L ********************************
