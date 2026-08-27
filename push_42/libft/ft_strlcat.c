/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:02:05 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:02:11 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && (i + j) < (size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// #include <bsd/string.h>
//
// int	main(void)
// {
// 	char	dst_forig[20];
// 	char	dst_frepl[20];
//
// 	strcpy(dst_forig, "Hello");
// 	strcpy(dst_frepl, "Hello");
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy Path): Append \" World\" into \"Hello\", size 20\n");
// 	printf("--> Return Value: Orig %zu | Repl %zu\n",
// 		strlcat(dst_forig, " World", 20), ft_strlcat(dst_frepl, " World", 20));
// 	printf("--> Mod Buffer: Orig \"%s\" | Repl \"%s\"\n",
// 		dst_forig, dst_frepl);
// 	bzero(dst_forig, 20);
// 	bzero(dst_frepl, 20);
// 	strcpy(dst_forig, "Hello");
// 	strcpy(dst_frepl, "Hello");
// 	printf("************************************************************\n");
// 	printf("Test 1 (Truncation): Append \" World\" into \"Hello\", size 8\n");
// 	printf("--> Return Value: Orig %zu | Repl %zu\n",
// 		strlcat(dst_forig, " World", 8), ft_strlcat(dst_frepl, " World", 8));
// 	printf("--> Mod Buffer: Orig \"%s\" | Repl \"%s\"\n",
// 		dst_forig, dst_frepl);
// 	bzero(dst_frepl, 20);
// 	strcpy(dst_frepl, "Hello");
// 	printf("--> Truncation: Returned Value %zu vs Mod Buffer Length %zu\n",
// 		ft_strlcat(dst_frepl, " World", 8), strlen(dst_frepl));
// 	bzero(dst_forig, 20);
// 	bzero(dst_frepl, 20);
// 	strcpy(dst_forig, "Hello");
// 	strcpy(dst_frepl, "Hello");
// 	printf("************************************************************\n");
// 	printf("Test 2 (Zero Size): Append \" World\" into \"Hello\", size 0\n");
// 	printf("--> Return Value: Orig %zu | Repl %zu\n",
// 		strlcat(dst_forig, " World", 0), ft_strlcat(dst_frepl, " World", 0));
// 	printf("--> Mod Buffer (must stay untouched): Orig \"%s\" | Repl \"%s\"\n",
// 		dst_forig, dst_frepl);
// 	bzero(dst_forig, 20);
// 	bzero(dst_frepl, 20);
// 	strcpy(dst_forig, "Hello");
// 	strcpy(dst_frepl, "Hello");
// 	printf("************************************************************\n");
// 	printf("Test 3 (strlen(dst) > size 5 return (size + ft_strlen(src))\n");
// 	printf("--> Return Value: Orig %zu | Repl %zu\n",
// 		strlcat(dst_forig, " World", 5), ft_strlcat(dst_frepl, " World", 5));
// 	printf("--> Mod Buffer (must stay untouched): Orig \"%s\" | Repl \"%s\"\n",
// 		dst_forig, dst_frepl);
// 	bzero(dst_forig, 20);
// 	bzero(dst_frepl, 20);
// 	strcpy(dst_forig, "");
// 	strcpy(dst_frepl, "");
// 	printf("************************************************************\n");
// 	printf("Test 4 (dst empty): dst=\"\", append \"World\", size 20\n");
// 	printf("--> Return Value: Orig %zu | Repl %zu\n",
// 		strlcat(dst_forig, "World", 20), ft_strlcat(dst_frepl, "World", 20));
// 	printf("--> Mod Buffer: Orig \"%s\" | Repl \"%s\"\n",
// 		dst_forig, dst_frepl);
// 	bzero(dst_forig, 20);
// 	bzero(dst_frepl, 20);
// 	strcpy(dst_forig, "Hello");
// 	strcpy(dst_frepl, "Hello");
// 	printf("************************************************************\n");
// 	printf("Test 5 (src empty): dst=\"Hello\", append \"\", size 20\n");
// 	printf("--> Return Value: Orig %zu | Repl %zu\n",
// 		strlcat(dst_forig, "", 20), ft_strlcat(dst_frepl, "", 20));
// 	printf("--> Mod Buffer: Orig \"%s\" | Repl \"%s\"\n",
// 		dst_forig, dst_frepl);
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The strlcat() function appends the NULL-terminated string src to the end of
// dst.  It will append at most size - strlen(dst) - 1 bytes, NULL-terminating
// the result.
// The strlcpy() and strlcat() functions copy/concatenate strings respectively.
// They are designed to be safer, more consistent, and less error prone
// replacements for strncpy(3) and strncat(3).  Unlike those functions,
// strlcpy() and strlcat() take the full size of the buffer (not just the
// length) and guarantee to NULL-terminate the result (as long as size is larger
// than 0 or, in the case of strlcat(), as long as there is at least
// one byte free in dst).  Note that a byte for the NULL should be included in
// size.  Also note that strlcpy() and strlcat() only operate on true “C”
// strings.  This means that for strlcpy() src must be NULL-terminated and for
// strlcat() both src and dst must be NULL-terminated.
// RETURN VALUES & ERRORS
// The strlcpy() and strlcat() functions return the total length of the
// string they tried to create.  For strlcpy() that means the length of src.
// For strlcat() that means the initial length of dst plus the length of src.
// While this may seem somewhat confusing, it was done to make truncation de‐
// tection simple.
// Note, however, that if strlcat() traverses size characters without finding
// a NULL, the length of the string is considered to be size and the destina‐
// tion string will not be NULL-terminated (since there was no space for the
// NULL).  This keeps strlcat() from running off the end of a string.  In
// practice this should not happen (as it means that either size is incorrect
// or that dst is not a proper “C” string).  The check exists to
// prevent potential security problems in incorrect code.
// ******************************* M A N U A L ********************************