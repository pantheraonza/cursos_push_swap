/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:01:45 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:01:46 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	orig1[20] = "Hello";
// 	char	repl1[20] = "Hello";

// 	printf("Tests with Original & Replicated Functions\n");
// 	printf("************************************************************\n");

// 	printf("Test 0 (Happy path): copy 5 bytes\n");

// 	memcpy(orig1, "World", 5);
// 	ft_memcpy(repl1, "World", 5);

// 	printf("--> Orig \"%s\" | Repl \"%s\"\n", orig1, repl1);

// 	printf("************************************************************\n");

// 	printf("Test 1 (Edge case): copy zero bytes\n");

// 	memcpy(orig1, "ABCDE", 0);
// 	ft_memcpy(repl1, "ABCDE", 0);

// 	printf("--> Orig \"%s\" | Repl \"%s\"\n", orig1, repl1);

// 	return (0);
// }

// ******************************* M A N U A L ********************************
// DESCRIPTION
// void *ft_memcpy(void *dest, const void *src, size_t n);
// Copies n bytes from the memory block pointed to by src
// into the memory block pointed to by dest.
//
// RETURN VALUES & ERRORS
// Returns dest.
// Returns NULL only if both dest and src are NULL.
//
// STRUCTURE
// unsigned char *ptr_dest;			view the destination as bytes
// const unsigned char *ptr_src;	view the source as bytes
// size_t i;						current byte being copied
//
// if (...)							protect against NULL pointers
// ptr_dest = ...					cast destination memory into bytes
// ptr_src = ...					cast source memory into bytes
// i = 0;							start from the first byte
// while (...)						copy each byte sequentially
// ptr_dest[i] = ptr_src[i];		copy one byte
// return (dest);					return the destination pointer
//
// There are edge cases to take into account:
// If n is 0, no bytes are copied.
// ft_memcpy does not stop when a '\0' byte is found.
// The source and destination memory regions MUST NOT overlap.
//
// Other important things to know:
// ft_memcpy works on raw memory rather than C strings.
// Each byte is copied independently from left to right.
// If the memory regions overlap, the behavior is undefined.
// In that situation, ft_memmove() must be used instead.
//
// ******************************* M A N U A L ********************************