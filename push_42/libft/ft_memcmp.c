/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:03:24 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:03:26 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	a[] = "Hello";
// 	char	b[] = "Hello";
// 	char	c[] = "Help";

// 	printf("Tests with Original & Replicated Functions\n");
// 	printf("************************************************************\n");

// 	printf("Test 0 (Happy path): compare identical memory blocks\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		memcmp(a, b, 5),
// 		ft_memcmp(a, b, 5));

// 	printf("************************************************************\n");

// 	printf("Test 1 (Edge case): first different byte\n");
// 	printf("--> Orig %d | Repl %d\n",
// 		memcmp(a, c, 5),
// 		ft_memcmp(a, c, 5));

// 	return (0);
// }

// ******************************* M A N U A L ********************************
// DESCRIPTION
// int ft_memcmp(const void *s, const void *s2, size_t n);
// Compares the first n bytes of two memory blocks.
// RETURN VALUES & ERRORS
// Returns 0 if all compared bytes are equal.
// Returns a negative value if the first differing byte in s
// is smaller than the corresponding byte in s2.
// Returns a positive value if it is greater.
// STRUCTURE
// const unsigned char *ptr1;		view the first memory block as bytes
// const unsigned char *ptr2;		view the second memory block as bytes
// size_t i;						current byte being compared
// ptr1 = (const unsigned char *)s;	cast the first memory block
// ptr2 = (const unsigned char *)s2;	cast the second memory block
// i = 0;							start from the first byte
// while (...)						compare each byte
// if (...)							first difference found
// return (...)						return the byte difference
// return (0)						all compared bytes are equal
// There are edge cases to take into account:
// ft_memcmp compares raw memory.
// It does NOT stop when a '\0' byte is found.
// If n is 0, no bytes are compared and 0 is returned.
// Other important things to know:
// Unlike ft_strncmp(), ft_memcmp() compares arbitrary memory,
// not C strings.
// The comparison is performed byte by byte using unsigned char,
// matching the behavior of the standard C library.
// ******************************* M A N U A L ********************************