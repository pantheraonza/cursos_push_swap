/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:14:11 by criredon          #+#    #+#             */
/*   Updated: 2026/07/06 14:14:13 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (ptr_dest < ptr_src)
		return (ft_memcpy(dest, src, n));
	i = n;
	while (i > 0)
	{
		i--;
		ptr_dest[i] = ptr_src[i];
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	orig[20] = "123456789";
// 	char	repl[20] = "123456789";

// 	printf("Tests with Original & Replicated Functions\n");
// 	printf("************************************************************\n");

// 	printf("Test 0 (Happy path): overlapping memory regions\n");

// 	memmove(orig + 2, orig, 5);
// 	ft_memmove(repl + 2, repl, 5);

// 	printf("--> Orig \"%s\" | Repl \"%s\"\n", orig, repl);

// 	printf("************************************************************\n");

// 	printf("Test 1 (Edge case): copy zero bytes\n");

// 	memmove(orig, "ABCDE", 0);
// 	ft_memmove(repl, "ABCDE", 0);

// 	printf("--> Orig \"%s\" | Repl \"%s\"\n", orig, repl);

// 	return (0);
// }

// ******************************* M A N U A L ********************************
// DESCRIPTION
// void *ft_memmove(void *dest, const void *src, size_t n);
// Copies n bytes from one memory region to another,
// correctly handling overlapping memory regions.
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
//
// if (ptr_dest < ptr_src)			no overlap risk while copying forward
// while (...)						copy from beginning to end
//
// else								possible overlap
// i = n;							start from the last byte
// while (...)						copy backwards
//
// return (dest);					return the destination pointer
//
// There are edge cases to take into account:
// If n is 0, no bytes are copied.
// ft_memmove does not stop when a '\0' byte is found.
// Source and destination memory regions may overlap safely.
//
// Other important things to know:
// ft_memmove behaves like ft_memcpy when the memory regions do
// not overlap.
// When overlap exists, copying backwards prevents source bytes
// from being overwritten before they are copied.
// This makes ft_memmove safe for every memory copy operation.
//
// ******************************* M A N U A L ********************************
