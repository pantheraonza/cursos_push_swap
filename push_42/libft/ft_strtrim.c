/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:01:45 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 17:01:47 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	stop;
	char	*new;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	stop = ft_strlen(s1);
	while (stop > start && ft_strchr(set, s1[stop - 1]))
		stop--;
	new = malloc((stop - start + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, (s1 + start), (stop - start + 1));
	return (new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*r;

// 	printf("Tests with Replicated Function (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): trim(\"   hello world   \", \" \")\n");
// 	r = ft_strtrim("   hello world   ", " ");
// 	printf("--> Repl \"%s\"\n", r);
// 	free(r);
// 	printf("************************************************************\n");
// 	printf("Test 1 (Entire string in set, size_t underflow risk): \"xxx\"\n");
// 	r = ft_strtrim("xxx", "x");
// 	printf("--> Repl \"%s\" (empty, not NULL — no underflow)\n", r);
// 	free(r);
// 	return (0);
// }
//
// ******************************** M A N U A L ********************************
// DESCRIPTION
// char *ft_strtrim(char const *s1, char const *set);
// Allocates (with malloc) and returns a copy of s1 with the
// characters in set removed from both its beginning and its end.
// RETURN VALUES & ERRORS
// Returns the trimmed string, or NULL if the memory allocation fails.
// The function ft_strtrim DOES NOT modify the original string.
// It CREATES a NEW string by removing the characters found in 'set'
// from the beginning and the end of the original string.
// STRUCTURE
// size_t start       	index of the first character to keep
// size_t stop         	index just after the last character to keep
// char *new          	pointer to the newly allocated trimmed string
// if (s1 == NULL)    	safety check: if string/set do not exist, return NULL
// while (...)        	move start forward (or end backward) while characters
// 						belong to trimming set
// end = ft_strlen(s1)	initialize end at the end of the string
// new = malloc(...)	allocate enough memory for string including '\0'
// if (new == NULL)		safety check: if memory allocation fails, return NULL
// ft_strlcpy(...)		copy the remaining characters starting at
//                      s1 + start into the new string
// return (new)			return the pointer to the newly created string
// There are edge cases to take into account:
// ft_strtrim returns NULL if s1 == NULL, set == NULL, or if malloc fails.
// If every character belongs to 'set', the function returns an allocated
// empty string ("").
// Other important things to know:
// The expression (s1 + start) DOES NOT create a new string.
// It simply moves the pointer to the first character that should be kept.
// The condition (end > start) prevents size_t underflow when the entire
// string must be trimmed.
// ******************************* M A N U A L ********************************
