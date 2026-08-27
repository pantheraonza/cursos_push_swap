/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:01:12 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 17:01:13 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*r;

// 	printf("Tests with Replicated Function (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): substr(\"hello world\", 8, 5)\n");
// 	r = ft_substr("hello world", 8, 5);
// 	printf("--> Repl \"%s\"\n", r);
// 	free(r);
// 	printf("************************************************************\n");
// 	printf("Test 1 (start beyond string length, must return empty)\n");
// 	r = ft_substr("hello world", 11, 5);
// 	printf("--> Repl \"%s\" (expected empty, not NULL)\n", r);
// 	free(r);
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// Allocates (with malloc(3)) and returns a substring from s. The
// substring begins at index start and has a maximum length of len.
// RETURN VALUES & ERRORS
// Returns the resulting substring, or NULL if the memory allocation fails.
// IN DEEPTH UNDERSTANDING
// The function ft_substr DOES NOT modify the original string.
// It CREATES a NEW string containing a portion (substring) of the original.
// We use to optimize: ft_strlcpy(char *dst, const char *src, size_t size)
// char *new                 pointer to the newly allocated substring
// if (start >= ft_strlen(s))      if start is beyond the end of the string,
//                                 return an empty string
// else if (len > ft_strlen(s) - start)
//                                 adjust len so it does not exceed the
//                                 remaining characters in the string
// new = malloc(...)		allocate memory for the substring,
//                                 including the terminating '\0'
// if (new == NULL)  		safety check: if memory allocation fails,
//                                 return NULL
// ft_strlcpy(...)                copy len characters starting at
//                                s + start into the new substring
// return (new)			return the pointer to the newly string
// There are edge cases to take into account:
// ft_substr will return an empty string if start >= ft_strlen(s), truncate
// len if it exceeds the remaining characters, and return NULL if malloc
// fails.
// Other important things to know:
// The expression 's + start' DOES NOT create a new string. It simply moves
// the pointer to the starting position from which ft_strlcpy begins copying.
// ******************************* M A N U A L ********************************