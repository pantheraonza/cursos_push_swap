/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:01:14 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:01:15 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buf_orig[11];
// 	char	buf_repl[11];

// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): fill 5 bytes with 'A'\n");
// 	memset(buf_orig, 'A', 5);
// 	ft_memset(buf_repl, 'A', 5);
// 	buf_orig[5] = '\0';
// 	buf_repl[5] = '\0';
// 	printf("--> Orig \"%s\" | Repl \"%s\"\n", buf_orig, buf_repl);
// 	printf("************************************************************\n");
// 	printf("Test 1 (memset DOES NOT append '\\0')\n");
// 	/* Fill the whole buffer with '.' first */
// 	memset(buf_orig, '.', sizeof(buf_orig));
// 	memset(buf_repl, '.', sizeof(buf_repl));
// 	/* Overwrite only the first 5 bytes */
// 	memset(buf_orig, 'A', 5);
// 	ft_memset(buf_repl, 'A', 5);
// 	/* Add '\0' manually ONLY for safe printing */
// 	buf_orig[10] = '\0';
// 	buf_repl[10] = '\0';
// 	printf("--> Orig \"%s\" | Repl \"%s\"\n", buf_orig, buf_repl);
// 	printf("To prove memset only modified 5 bytes and DOES NOT append '\\0'\n");
// 	printf("the tester fills the whole buffer with '.' first, and than\n");
// 	printf("overwrite first 5 bytes with \"A\", adding terminator.\n");
// 	return (0);
// }

/* ******************************* M A N U A L *********************************
DESCRIPTION
The  memset()  function fills the first n bytes of the memory area pointed
to by s with the constant byte c.
RETURN VALUES & ERRORS
The memset() function returns a pointer to the memory area s.
EXTRA NOTES BY CRIREDON
It is the fastest and most efficient way to initialize an array, zero out
a structure, or set memory to zero.
void *s: A pointer to the block of memory you want to fill. It is a void *
because memset doesn't care if you pass an array of int, char, or a struct;
it only sees raw memory.
int c: The value to be copied. Even though it is passed as an int, the function
internally converts it to an unsigned char (1 byte) before writing it.
size_t n: The number of bytes to be filled.
******************************** M A N U A L ******************************** */