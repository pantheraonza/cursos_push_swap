/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:07:38 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:07:39 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <bsd/string.h>

// int	main(void)
// {
// 	char	dst1[10];
// 	char	dst2[10];
// 	char	*src;

// 	src = "Hello";
// 	printf("Tests with Original & Replicated Functions\n");
// 	printf("************************************************************\n");
// 	printf("Copy \"Hello\" into size 10: Orig %zu | Repl %zu\n",
// 		strlcpy(dst1, src, 10), ft_strlcpy(dst2, src, 10));
// 	printf("Orig dst: %s | Repl dst: %s\n", dst1, dst2);
// 	bzero(dst1, 10);
// 	bzero(dst2, 10);
// 	printf("Copy \"hello\" into size 3: Orig %zu | Repl %zu\n",
// 		strlcpy(dst1, src, 3), ft_strlcpy(dst2, src, 3));
// 	printf("Orig dst: %s | Repl dst: %s\n", dst1, dst2);
// 	bzero(dst1, 10);
// 	bzero(dst2, 10);
// 	printf("Copy \"hello\" into size 0: Orig %zu | Repl %zu\n",
// 		strlcpy(dst1, src, 0), ft_strlcpy(dst2, src, 0));
// 	printf("Orig dst: %s | Repl dst: %s\n", dst1, dst2);
// 	return (0);
// }

// ******************************** M A N U A L ********************************
// DESCRIPTION
// The strlcpy() function copies up to size - 1 characters from the
// null-terminated string src to dst, null-terminating the result.
// It is designed to be safer alternatives to strcpy(). It guarantees
// that dst is null-terminated as long as size is not 0.
// RETURN VALUES
// Returns the total length of the string src (not including the null
// terminator). This allows the caller to detect truncation: if the
// return value is >= size, truncation occurred.
// NOTES FROM THE MAN
// Note that the destination string must be large enough to hold the
// result. A destination string that is too short can be a security risk.
// EXTRA NOTES BY CRIREDON - EDGE CASES
// This function does not have NULL check as its default behaviour.
// 1. When size is 0, we must NOT touch dst at all — the function just
//    returns src_len. This is why size == 0 is checked before the copy.
// 2. The copy loop stops at size - 1 characters to leave room for '\0'.
//    dst[i] = '\0' is always written after the copy loop — this is
//    the null-termination guarantee that makes strlcpy safer than strncpy.
// INSTRUCTION TO COMPILE
// Compile with: cc -Wall -Wextra -Werror -lbsd ft_strlcpy.c ft_strlen.c
//****************************** M A N U A L *******************************