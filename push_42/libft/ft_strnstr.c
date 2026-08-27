/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:03:36 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:03:37 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// #include <bsd/string.h>
//
// int	main(void)
// {
// 	char	*str;
//
// 	str = "Hello world";
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): Find \"world\" in full string, n=9\n");
// 	printf("--> Orig %p | Repl %p\n",
// 		strnstr(str, "wor", 11), ft_strnstr(str, "wor", 11));
// 	printf("************************************************************\n");
// 	printf("Test 1 (Truncated search window cuts off the match): n=8\n");
// 	printf("--> Orig %p | Repl %p\n",
// 		strnstr(str, "wor", 8), ft_strnstr(str, "wor", 8));
// 	printf("************************************************************\n");
// 	printf("Test 2 (Empty little, must return big unchanged)\n");
// 	printf("--> Orig %p | Repl %p (addr %p)\n",
// 		strnstr(str, "", 11), ft_strnstr(str, "", 11),
// 		(void *)str);
// 	printf("************************************************************\n");
// 	printf("Test 3 (Little not found anywhere): \"xyz\"\n");
// 	printf("--> Orig %p | Repl %p\n",
// 		strnstr(str, "xyz", 11), ft_strnstr(str, "xyz", 11));
// 	printf("************************************************************\n");
// 	printf("Test 4 (Match starts exactly at the last possible index)\n");
// 	printf("--> Orig %p | Repl %p\n",
// 		strnstr(str, "d", 11), ft_strnstr(str, "d", 11));
// 	printf("************************************************************\n");
// 	printf("Test 5 (little longer than len, can never fit, must fail)\n");
// 	printf("--> Orig %p | Repl %p\n",
// 		strnstr(str, "hello world!", 5),
// 		ft_strnstr(str, "hello world!", 5));
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The strnstr() function locates the first occurrence of the
// NULL-terminated string little in the string big, where not more
// than len characters of big are searched. Characters in big after a
// NULL byte are not searched.
// RETURN VALUES & ERRORS
// If little is an empty string, big is returned.
// If little is not found within the first len characters, NULL is returned.
// Otherwise a pointer to the first matching position is returned.
// INSTRUCTIONS FOR COMPILATION
// Since strnstr is a function from another library, it is necessary to
// compile using the flag -lbsd.
// ******************************* M A N U A L ********************************
